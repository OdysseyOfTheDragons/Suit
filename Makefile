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
FLAGS=-I. -g -Os -s -O3 $(WARNINGS)
EFLAGS=-static-libasan -lm -ledit

# Sources
MAIN=main.c
CSRC=cli/colors/colors.c \
	 cli/strings/strings.c \
	 cli/options/options.c \
	 cli/parser/parser.c \
	 lib/common.c \
	 lib/editline.c \
	 lib/error.c
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
	@$(CC) $(FLAGS) -MM -MD -o $@ $<

$(OUT): $(OSRC)
	@$(CC) $(FLAGS) -o $@ $+ $(EFLAGS)

run:
	@./build/suit

format: $(CSRC) $(HSRC)
	@indent -linux $^

valgrind: $(OUT)
	@valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)

.PHONY: clean
clean:
	@rm -f main $(OSRC) $(DSRC) *.i *.s

.PHONY: archive
archive: format
	@-tar -zcf main.tar.gz Makefile docs/ $(SRC) $(HSRC)

# Automatic dependences
-include $(DSRC)
