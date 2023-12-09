#include "maths/maths.h"

/// Absolute value
///
/// \param x Value from which we get the absolute value
/// \return $\abs{x}$
unsigned int _abs(int x)
{
	if (x < 0) {
		return -x;
	}
	return x;
}

/// Maximum between two values
///
/// \param x1 THe first value
/// \param x2 The second value
/// \return $\max{x1, x2}$
int _max(int x1, int x2)
{
	if (x1 > x2) {
		return x1;
	}
	return x2;
}

/// Minimum between two values
///
/// \param x1 THe first value
/// \param x2 The second value
/// \return $\min{x1, x2}$
int _min(int x1, int x2)
{
	if (x1 < x2) {
		return x1;
	}
	return x2;
}
