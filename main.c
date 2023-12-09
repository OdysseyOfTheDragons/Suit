#include "lib/common.h"
#include "lib/error.h"
#include "cli/colors/colors.h"
#include "cli/options/options.h"
#include "cli/parser/parser.h"

int main(void) {
	print_header();
	parse();
	return EXIT_SUCCESS;
}
