#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "mallocf.h"

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

  buf = malloc( sizeof(char) * (1 + vstrlenf( fmt, args )) );

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
  result = vsnprintf( &buf, 0, fmt, args );
  va_end( args );

  return result;
}

size_t vstrlenf( const char *fmt, va_list args )
{
  char buf;

  return vsnprintf( &buf, 0, fmt, args );
}
