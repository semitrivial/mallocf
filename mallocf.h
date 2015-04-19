#ifndef MALLOCF_INCLUDE_GUARD
#define MALLOCF_INCLUDE_GUARD

#include <stdarg.h>//va_start, va_end, va_list
#include <stdlib.h>//size_t, malloc

char *strdupf( const char *fmt, ... );
char *vstrdupf( const char *fmt, va_list args );
size_t strlenf( const char *fmt, ... );
size_t vstrlenf( const char *fmt, va_list args );

#endif // MALLOCF_INCLUDE_GUARD
