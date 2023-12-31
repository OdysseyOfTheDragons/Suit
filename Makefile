# Compiler
CC=gcc

# Warnings
WERROR=-Wall -Wextra -pedantic
WLEAK=-fsanitize=address
WSTACK=-fstack-protector-all -fstack-protector-strong -fstack-clash-protection
WFORMAT=-Wformat=2 -Werror=implicit-function-declaration
WCOMMON=-Wshadow -Wdouble-promotion \
		-fno-common -ffunction-sections -fdata-sections
WARNINGS=$(WERROR) $(WLEAK) $(WSTACK) $(WFORMAT) $(WCOMMON)

# Flags
HELP=-g
BUILD=-I. -Os -s -O3 $(HELP)
FLAGS=$(BUILD) $(WARNINGS)
EFLAGS=-lm -ledit

# Sources
MAIN=main.c
CSRC=cli/colors/colors.c \
	 cli/strings/strings.c \
	 cli/options/options.c \
	 cli/parser/parser.c \
	 lib/common.c \
	 lib/editline.c \
	 lib/error.c \
	 maths/maths.c \
	 polynomials/polynomials.c \
	 store/store.c
OSRC=$(CSRC:.c=.o) $(MAIN:.c=.o)
DSRC=$(CSRC:.c=.d) $(MAIN:.c=.d)
HSRC=$(CSRC:.c=.h)
SRC=$(MAIN) $(CSRC)

OUT=build/suit

.PHONY: all
all: format $(OUT) run
	
# File compilation
%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< $(EFLAGS)

%.d: %.c
	@$(CC) $(FLAGS) -MM -MD -o $@ $< $(EFLAGS)

$(OUT): $(OSRC)
	@$(CC) $(FLAGS) -o $@ $+ $(EFLAGS)

.PHONY: release
release:
	@make $(OUT) FLAGS='$(BUILD)'

run:
	@./build/suit

# Beauty of the code
format: $(CSRC) $(HSRC)
	@indent -linux $^

# Testing for memory leaks
valgrind: $(OUT)
	@valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)

# Clean architecture
.PHONY: clean
clean:
	@rm -f main $(OSRC) $(DSRC) *.i *.s

# Archive project
.PHONY: archive
archive: format
	@-tar -zcf main.tar.gz Makefile docs/ $(SRC) $(HSRC)

# Automatic dependences
-include $(DSRC)
