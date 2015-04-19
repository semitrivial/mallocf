#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "mallocf.h"

#ifdef __va_copy
  #define mallocf_va_copy(dest,src) __va_copy((dest),(src))
  #define mallocf_va_end_copy(cpy) va_end(cpy)
#else
  #ifdef va_copy
    #define mallocf_va_copy(dest,src) va_copy((dest),(src))
    #define mallocf_va_end_copy(cpy) va_end(cpy)
  #else
    #define mallocf_va_copy(dest,src) (dest)=(src)
    #define mallocf_va_end_copy(cpy) do {} while(0)
  #endif
#endif

char *strdupf( const char *fmt, ... )
{
  char *result;
  va_list args;

  va_start( args, fmt );
  result = vstrdupf( fmt, args );
  va_end( args );

  return result;
}

char *vstrdupf( const char *fmt, va_list args )
{
  char *buf;
  va_list copy;

  mallocf_va_copy( copy, args );

  buf = malloc( sizeof(char) * (1 + vstrlenf( fmt, args )) );

  mallocf_va_end_copy( copy );

  if ( !buf )
    return NULL;

  vsprintf( buf, fmt, args );

  return buf;
}

size_t strlenf( const char *fmt, ... )
{
  va_list args;
  size_t result;
  char buf;

  va_start( args, fmt );
  /*
   * vsnprintf returns the number of chars that could
   * not be printed due to size limit.  So we call it
   * with size limit 0 to get the desired length.
   */
  result = vsnprintf( &buf, 0, fmt, args );
  va_end( args );

  return result;
}

size_t vstrlenf( const char *fmt, va_list args )
{
  char buf;

  /*
   * vsnprintf returns the number of chars that could
   * not be printed due to size limit.  So we call it
   * with size limit 0 to get the desired length.
   */
  return vsnprintf( &buf, 0, fmt, args );
}
