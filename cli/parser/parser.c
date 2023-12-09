#include "cli/parser/parser.h"
#include "lib/common.h"
#include "lib/editline.h"
#include "cli/colors/colors.h"

void parse()
{
	// Infinite loop
	while (true) {
		// Get user input
		print("[bold][fg(green)]$ [/fg(green)][/bold]");
		char *input = readline("");
		add_history(input);

		// We typed exit?
		if (strcmp(input, "exit()") == 0) {
			// TODO: empty all stores
			free(input);
			break;
		}

		printf("You typed '%s'\n", input);
		free(input);
	}
}
