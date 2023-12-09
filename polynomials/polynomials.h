#ifndef _POLYNOMIALS
#define _POLYNOMIALS
#include "lib/common.h"

typedef struct Polynomial polynomial;

polynomial *create_p(int degree, int *coefficients);
void delete_p(polynomial * p);
void print_p(polynomial * p, bool beauty_print);
int evaluate_p(polynomial * p, float x);
bool equality_p(polynomial * p1, polynomial * p2);
polynomial *derive_p(polynomial * p);
polynomial *sum_p(polynomial * p1, polynomial * p2);
polynomial *multiply_p(polynomial * p1, polynomial * p2);
#endif
