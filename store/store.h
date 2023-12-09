#ifndef _STORE
#define _STORE
#include "lib/common.h"
#include "polynomials/polynomials.h"

typedef struct Vector vector;

vector *create_vector();
void delete_vector(vector * v);
void append_vector(vector * v, polynomial * p);
polynomial *get_vector(vector * v, int index);
void remove_vector(vector * v, int index);
#endif
