#include "cli/parser/parser.h"
#include "lib/common.h"
#include "lib/editline.h"
#include "cli/colors/colors.h"
#include "cli/strings/strings.h"
#include "cli/options/options.h"
#include "store/store.h"

void parse()
{
	// Create a vector to store all following polynomials
	vector *store = create_vector();

	// Infinite loop
	while (true) {
		// Get user input
		char *input = readline("$ ");
		add_history(input);

		// We typed exit? help? license? version?
		// We trim to consider "  help " as "help"
		char *trimmed = trim(input);
		if (strcmp(trimmed, "exit") == 0) {
			// TODO: empty all stores
			delete_vector(store);
			free(trimmed);
			free(input);

			return;
		} else if (strcmp(trimmed, "author") == 0) {
			print_author();
		} else if (strcmp(trimmed, "help") == 0) {
			print_help();
		} else if (strcmp(trimmed, "license") == 0) {
			print_license();
		} else if (strcmp(trimmed, "version") == 0) {
			print_version();
		} else {
			printf("You typed '%s'\n", input);
		}

		free(trimmed);
		free(input);
	}

	delete_vector(store);
}
