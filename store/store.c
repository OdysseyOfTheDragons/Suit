#include "store/store.h"
#include "lib/common.h"
#include "polynomials/polynomials.h"
#include "lib/error.h"

struct Vector {
	int length;
	int capacity;
	polynomial **p;
};

vector *create_vector()
{
	vector *v = (vector *) malloc(sizeof(vector));

	v->capacity = 0;
	v->length = 0;

	v->p = (polynomial **) malloc((v->capacity + 1) * sizeof(polynomial *));

	return v;
}

void delete_vector(vector * v)
{
	for (int i = 0; i < v->length; i++) {
		delete_p(v->p[i]);
	}

	free(v->p);
	free(v);
}

// Needed to set the new capacity
void resize_vector(vector * v, int length)
{
	if (length <= v->capacity / 4 || length >= v->capacity) {
		// Either too much empty space, or too few space
		v->capacity = 2 * length;
		polynomial **new_coeffs =
		    (polynomial **) malloc(v->capacity * sizeof(polynomial *));

		for (int i = 0; i < v->length && i < length; i++) {
			new_coeffs[i] = v->p[i];
		}

		free(v->p);
		v->p = new_coeffs;
	}

	v->length = length;
}

void append_vector(vector * v, polynomial * p)
{
	resize_vector(v, v->length + 1);
	v->p[v->length - 1] = p;
}

polynomial *get_vector(vector * v, int index)
{
	safecheck(index >= 0 && index < v->length,
		  "Assert `get_vector` index.\n");
	return v->p[index];
}

void remove_vector(vector * v, int index)
{
	safecheck(index >= 0 && index < v->length,
		  "Assert `remove_vector` index.\n");

	delete_p(v->p[index]);

	// Copy all following elements one place before
	for (int i = index + 1; i < v->length; i++) {
		v->p[i - 1] = v->p[i];
	}

	// Decrease length
	resize_vector(v, v->length - 1);
}
