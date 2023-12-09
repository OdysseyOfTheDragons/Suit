#include "cli/colors/colors.h"
#include "lib/common.h"
#include "cli/strings/strings.h"

/// Clears the word and reset the counter
void clear_word(string * word, int *counter)
{
	clear_string(word);
	*counter = 0;
}

void print(char *msg)
{
	// We parse the string char by char
	// When we get a tag, we call the according function

	int length = strlen(msg);
	string *word = create_string();

	int word_length_counter = 0;
	for (int i = 0; i < length; i++) {
		// We add the new char to the word
		append_char(word, msg[i]);
		/* word[word_length_counter] = msg[i]; */
		word_length_counter++;

		// We must first recognize whether we have a keyword
		// If we have, we call the good function, and we clear word
		if (cmp(word, "[reset]")) {
			printf("\033[0m");
			clear_word(word, &word_length_counter);
		}

		else if (cmp(word, "[bold]")) {
			printf("\033[1m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[/bold]")) {
			printf("\033[22m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[italic]")) {
			printf("\033[3m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[/italic]")) {
			printf("\033[23m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[underline]")) {
			printf("\033[4m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[/underline]")) {
			printf("\033[24m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[blink]")) {
			printf("\033[5m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[/blink]")) {
			printf("\033[25m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[/strike]")) {
			printf("\033[9m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[/strike]")) {
			printf("\033[29m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[space]")) {
			printf("\t");
			clear_word(word, &word_length_counter);
		}

		else if (cmp(word, "[fg(black)]")
			 || cmp(word, "[/fg(red)]")
			 || cmp(word, "[/fg(green)]")
			 || cmp(word, "[/fg(yellow)]")
			 || cmp(word, "[/fg(blue)]")
			 || cmp(word, "[/fg(magenta)]")
			 || cmp(word, "[/fg(cyan)]")
			 || cmp(word, "[/fg(white)]")) {
			printf("\033[30m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[fg(red)]")) {
			printf("\033[31m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[fg(green)]")) {
			printf("\033[32m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[fg(yellow)]")) {
			printf("\033[33m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[fg(blue)]")) {
			printf("\033[34m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[fg(magenta)]")) {
			printf("\033[35m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[fg(cyan)]")) {
			printf("\033[36m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[fg(white)]")) {
			printf("\033[97m");
			clear_word(word, &word_length_counter);
		}

		else if (cmp(word, "[bg(black)]")) {
			printf("\033[40m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[bg(red)]")) {
			printf("\033[41m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[bg(green)]")) {
			printf("\033[42m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[bg(yellow)]")) {
			printf("\033[43m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[bg(blue)]")) {
			printf("\033[44m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[bg(magenta)]")) {
			printf("\033[45m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[bg(cyan)]")) {
			printf("\033[46m");
			clear_word(word, &word_length_counter);
		} else if (cmp(word, "[bg(white)]")
			   || cmp(word, "[/bg(black)]")
			   || cmp(word, "[/bg(red)]")
			   || cmp(word, "[/bg(green)]")
			   || cmp(word, "[/bg(yellow)]")
			   || cmp(word, "[/bg(blue)]")
			   || cmp(word, "[/bg(magenta)]")
			   || cmp(word, "[/bg(cyan)]")) {
			printf("\033[107m");
			clear_word(word, &word_length_counter);
		}
		// We get if there is a space or a new line
		// If we have, we print word and we clear it
		else if (msg[i] == ' ' || msg[i] == '\t'
			 || msg[i] == '\n' || msg[i] == '\r') {
			printf("%s", string_content(word));
			clear_word(word, &word_length_counter);
		}
		// If next word is a tag, we need to separate it,
		// so we create a new word if the next char is [
		else if (i < length - 1 && msg[i + 1] == '[') {
			printf("%s", string_content(word));
			clear_word(word, &word_length_counter);
		}
	}

	// We print what is left of the msg
	printf("%s", string_content(word));

	// We free memory
	delete_string(word);
}
