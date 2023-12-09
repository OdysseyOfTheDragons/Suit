#include "cli/strings/strings.h"
#include "lib/common.h"

struct STRING {
	char *string;
	int length;
	int capacity;
};

string *create_string()
{
	string *str = (string *) malloc(sizeof(string));
	str->string = (char *)malloc(sizeof(char));
	str->length = 0;
	str->capacity = 1;

	str->string[0] = '\0';

	return str;
}

void append_char(string * str, char c)
{
	if (str->length + 1 >= str->capacity) {
		str->capacity *= 2;
		char *new_string = (char *)malloc(str->capacity * sizeof(char));

		// We create a new string filled with the ancient elements
		// of \0 (so we don't have to care about that null element later)
		for (int i = 0; i < str->capacity; i++) {
			if (i < str->length) {
				new_string[i] = str->string[i];
			} else {
				new_string[i] = '\0';
			}
		}

		free(str->string);
		str->string = new_string;
	}
	// We add the new element
	str->string[str->length] = c;
	str->length = str->length + 1;
}

int len(string * str)
{
	return str->length;
}

bool cmp_strings(string * s1, string * s2)
{
	if (s1->length != s2->length) {
		return false;
	}

	for (int i = 0; i < s1->length; i++) {
		if (s1->string[i] != s2->string[i]) {
			return false;
		}
	}

	return true;
}

bool cmp(string * str, char *s)
{
	int length = strlen(s);

	if (length != len(str)) {
		return false;
	}

	for (int i = 0; i < str->length; i++) {
		if (str->string[i] != s[i]) {
			return false;
		}
	}

	return true;
}

void clear_string(string * str)
{
	string *new_empty_string = create_string();

	free(str->string);
	str->string = new_empty_string->string;

	str->length = new_empty_string->length;
	str->capacity = new_empty_string->capacity;

	free(new_empty_string);
}

char *string_content(string * str)
{
	return str->string;
}

void delete_string(string * str)
{
	free(str->string);
	free(str);
}

void trim_string(string * str)
{
	// We create a new string without any whitespace
	string *new_str = create_string();

	for (int i = 0; i < str->length; i++) {
		char c = str->string[i];
		if (c != ' ' && c != '\t' && c != '\r' && c != '\n') {
			append_char(new_str, c);
		}
	}

	// We replace the old string
	free(str->string);
	str->string = new_str->string;

	str->length = new_str->length;
	str->capacity = new_str->capacity;

	free(new_str);
}
