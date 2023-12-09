#include "polynomials/polynomials.h"
#include "lib/common.h"
#include "cli/colors/colors.h"
#include "maths/maths.h"

/// Structure of a polynomial
struct Polynomial {
	int degree;
	int *coefficients;
};

/// Create a custom polynomial
///
/// \param length The number of coefficients
/// \param coefficients An array of coefficients for the polynomial
/// \returns A pointer to the polynomial
polynomial *create_polynomial(int length, int *coefficients)
{
	polynomial *p = (polynomial *) malloc(sizeof(polynomial));

	// Decrease degree while last coefficient is 0
	while (length > 1 && coefficients[length - 1] == 0) {
		length--;
	}

	// Create coefficients
	int *c = (int *)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++) {
		c[i] = coefficients[i];
	}

	p->degree = length - 1;
	p->coefficients = c;

	return p;
}

/// Delete a polynomial, to prevent memory leaks
///
/// \param p The polynomial
void delete_polynomial(polynomial * p)
{
	free(p->coefficients);
	free(p);
}

/// Print a given polynomial
///
/// \param p The polynomial to print
/// \param beauty_print If `@beauty_print` is enabled
void print_polynomial(polynomial * p, bool beauty_print)
{
	int d = p->degree;
	int *c = p->coefficients;

	if (!beauty_print) {
		print("[fg(green)]POLYNOMIAL:[/fg(green)] ");
	}

	for (int i = d; i >= 0; i--) {
		if (c[i] == 0) {
			continue;
		}
		// First coefficient has sign close to the coefficient
		if (i == d) {
			printf("%d", c[i]);
		} else {
			printf(" %c ", c[i] < 0 ? '-' : '+');
			if (c[i] < 0) {
				printf("%d", -c[i]);
			} else {
				printf("%d", c[i]);
			}
		}

		// Print x to the power of a the current degree
		if (i == 0) {
			continue;
		} else if (i == 1) {
			printf("x");
		} else {
			printf("x^%d", i);
		}
	}

	// If our polynomial is only 0
	if (d == 0 && c[0] == 0) {
		print("0");
	}
}

/// Evaluate a polynomial for a given `x` value
///
/// \param p The polynomial
/// \param x The value to evaluate the polynomial to
/// \returns $p(x)$
int evaluate_polynomial(polynomial * p, float x)
{
	int res = 0;
	for (int i = p->degree; i >= 0; i++) {
		res = res * x + p->coefficients[i];
	}

	return res;
}

/// Test whether two polynomials are equal
///
/// \param p1 The first polynomial
/// \param p2 The second polynomial
/// \returns `p1 == p2`
bool equality_polynomial(polynomial * p1, polynomial * p2)
{
	if (p1->degree != p2->degree) {
		return false;
	}

	for (int i = 0; i <= p1->degree; i++) {
		if (p1->coefficients[i] != p2->coefficients[i]) {
			return false;
		}
	}

	return true;
}

/// Get the polynomial with the highest degree, or the first if they
/// are equal
///
/// \param p1 The first polynomial
/// \param p2 The second polynomial
/// \return $\max{p1, p2}
polynomial *max_polynomial(polynomial * p1, polynomial * p2)
{
	int m = _max(p1->degree, p2->degree);

	if (m == p1->degree) {
		return p1;
	}
	return p2;
}

/// Derive the given polynomial
///
/// \param p The polynomial
/// \returns $p'(x)$
polynomial *derive_polynomial(polynomial * p)
{
	// Case: polynomial with only a constant
	if (p->degree == 0) {
		int length = 1;
		int *coefficients = (int *)malloc(length * sizeof(int));

		coefficients[0] = 0;

		polynomial *poly = create_polynomial(length, coefficients);
		free(coefficients);

		return poly;
	}
	// length = p->degree because p->degree is the number of coefficients
	// minus one already
	int length = p->degree;
	int *coefficients = (int *)malloc(length * sizeof(int));

	// Start from 1, because the coefficient at degree 0 will disappear
	for (int i = 1; i <= p->degree; i++) {
		coefficients[i - 1] = p->coefficients[i] * i;
	}

	polynomial *poly = create_polynomial(length, coefficients);
	free(coefficients);

	return poly;
}

/// Sum two polynomials
///
/// \param p1 The first polynomial
/// \param p2 The second polynomial
/// \return $p1 + p2$
polynomial *sum_polynomial(polynomial * p1, polynomial * p2)
{
	polynomial *max = max_polynomial(p1, p2);

	int max_degree = max->degree;
	int min_degree = 0;
	if (max_degree == p1->degree) {
		min_degree = p2->degree;
	} else {
		min_degree = p1->degree;
	}

	int degree = max_degree + 1;
	int *coefficients = (int *)malloc(degree * sizeof(int));

	// First sum all coefficients up to the common degree
	for (int i = 0; i <= min_degree; i++) {
		coefficients[i] = p1->coefficients[i] + p2->coefficients[i];
	}

	// Then add all coefficients of the max polynomial
	for (int i = min_degree + 1; i <= max_degree; i++) {
		coefficients[i] = max->coefficients[i];
	}

	polynomial *p = create_polynomial(degree, coefficients);
	free(coefficients);

	return p;
}

/// Multiply two polynomials together
///
/// \param p1 The first polynomial
/// \param p2 The second polynomial
/// \return $p1 \times p2$
polynomial *multiply_polynomial(polynomial * p1, polynomial * p2)
{
	int degree = p1->degree + p2->degree + 1;
	int *coefficients = (int *)malloc(degree * sizeof(int));

	// Get each coefficient of the new polynomial
	for (int i = 0; i < degree; i++) {
		int coefficient = 0;

		// Calculate each coefficient
		for (int k = 0; k < i + 1; k++) {
			// Coefficients `a` and `b` must be defined
			int a = 0;
			int b = 0;

			if (k <= p1->degree) {
				a = p1->coefficients[k];
			}
			if (k <= p2->degree) {
				b = p2->coefficients[k];
			}

			coefficient += a * b;
		}

		coefficients[i] = coefficient;
	}

	polynomial *poly = create_polynomial(degree, coefficients);
	free(coefficients);

	return poly;
}
