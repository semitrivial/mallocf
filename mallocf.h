#ifndef MALLOCF_INCLUDE_GUARD
#define MALLOCF_INCLUDE_GUARD

#include <string.h>
#include <stdarg.h>
#include <ctype.h>

char *strdupf( const char *fmt, ... );
char *vstrdupf( const char *fmt, va_list args );
size_t strlenf( const char *fmt, ... );
size_t vstrlenf( const char *fmt, va_list args );

#endif
