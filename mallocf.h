#ifndef MALLOCF_INCLUDE_GUARD
#define MALLOCF_INCLUDE_GUARD

char *strdupf( const char *fmt, ... );
char *vstrdupf( const char *fmt, va_list args );
int strlenf( const char *fmt, ... );
int vstrlenf( const char *fmt, va_list args );

#endif // MALLOCF_INCLUDE_GUARD
