#ifndef _ERROR
#define _ERROR
#include "lib/common.h"

// Safe failing
#define safefail(fmt, ...) \
	_panic(__FILE__, __LINE__, fmt,  ##__VA_ARGS__)
#define safecheck(cond, fmt, ...) \
	((cond) ? ((void)0) : safefail(fmt, ##__VA_ARGS__))
void _panic(const char *file, int line, const char *fmt, ...);
#endif
