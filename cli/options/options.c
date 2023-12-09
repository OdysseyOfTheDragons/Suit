#include "cli/options/options.h"
#include "lib/common.h"
#include "cli/colors/colors.h"

#define _NAME "Suit"
#define _VERSION "1.0.0"
#define _AUTHOR "Alexandre Conseil"

#define LICENSE_URL "https://raw.githubusercontent.com/OdysseyOfTheDragons/Suit/main/LICENSE"
#define GITHUB_URL "https://github.com/OdysseyOfTheDragons/Suit/tree/main"
#define PERSONAL_WEBSITE "https://alexandreconseil.fr"

/// Print the version of the program
void print_version()
{
	print("[fg(green)]VERSION:[/fg(green)] ");
	print(_VERSION);
	print("\n");
}

/// Print the author of the program
void print_author()
{
	print("[fg(green)]AUTHOR:[/fg(green)] ");
	print(_AUTHOR);
	print("\n");

	print("\nGITHUB: ");
	print(GITHUB_URL);
	print("\nWEBSITE: ");
	print(PERSONAL_WEBSITE);
	print("\n");
}

/// Print the header of the CLI
void print_header()
{
	// Program's name
	print("[fg(magenta)]");
	print(_NAME);
	print("[/fg(magenta)] ");

	// Version
	print("[fg(green)]");
	print(_VERSION);
	print("[/fg(green)] ");

	// Time
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	printf("( %d.%d.%d %d:%d:%d )", timeinfo->tm_mday,
	       timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
	       timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

	// Next line
	print("\n");

	// Give help
	print("Type 'help', 'version', 'author'  or 'license' "
	      "for more information.\n");
	print("Type 'exit' to quit.\n");
}

/// Print the language help
void print_help()
{
	print("[fg(blue)]HELP:[/fg(blue)]\n");
	print("I am sorry to hear you need help...\n");
	print("The language details can't be shown here,\n");
	print("but you may read it here:\n\n");

	print("[fg(blue)]LINK:[/fg(blue)] ");
	print(GITHUB_URL);
	print("\n");
}

/// Print the CLI help
void print_help_cli()
{
	print("[fg(blue)]HELP:[/fg(blue)] ");
	print("CLI help input");
	print("\n");

	print("Base command: ");
	print("[program-name] [?file]\n\n");

	printf("program-name\tThe name of the program, used to launch "
	       "this CLI or the interpreter. It needs to be launched "
	       "with the `./` in front of.\n"
	       "file\tOptional relative path to a file, which would then be "
	       "interpreted, instead of starting the interactive CLI.\n");
}

/// Print the license
void print_license()
{
	print("\n[fg(blue)]LICENSE:[/fg(blue)] ");
	print("GNU GENERAL PUBLIC LICENSE");
	print("[/fg(blue)]\n");

	printf("Please read <%s>\n", LICENSE_URL);
}
