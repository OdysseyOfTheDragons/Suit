#ifndef _POLYNOMIALS
#define _POLYNOMIALS
#include "lib/common.h"

typedef struct Polynomial polynomial;

polynomial *create_p(int degree, int *coefficients);
void delete_p(polynomial * p);
void print_polynomial(polynomial * p, bool beauty_print);
int evaluate_polynomial(polynomial * p, float x);
bool equality_polynomial(polynomial * p1, polynomial * p2);
polynomial *derive_polynomial(polynomial * p);
polynomial *sum_polynomial(polynomial * p1, polynomial * p2);
polynomial *multiply_polynomial(polynomial * p1, polynomial * p2);
#endif
