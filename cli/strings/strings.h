#ifndef _STRINGS
#define _STRINGS
#include "lib/common.h"

/// All the parsers will need at one point a growable string
/// that would have some nice functions to use.
typedef struct STRING string;

/// Creates the string
string *create_string();

/// Appends a char to the string
void append_char(string * str, char c);

/// Returns the length of the string
int len(string * str);

/// Compare two strings
bool cmp_strings(string * s1, string * s2);

/// Compare a string and a char*
bool cmp(string * str, char *s);

/// Clears the string and set it back to empty
void clear_string(string * str);

/// If we need the content (to print for example)
char *string_content(string * str);

/// Delete the string
void delete_string(string * str);

/// Trim whitespaces
void trim_string(string * str);
#endif
