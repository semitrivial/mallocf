#include <stdio.h>//vsprintf and vsnprintf
#include "mallocf.h"

/*
 * Utility function needed to avoid encoding errors
 */
size_t vstrlenf_verbose( const char *fmt, va_list args, int *err );

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
  size_t size;
  int encoding_err = 0;

  va_copy( copy, args );

  size = vstrlenf_verbose( fmt, copy, &encoding_err );

  va_end( copy );

  if ( !size )
  {
    /*
     * If vstrlenf_verbose returns 0, either the string really is
     * zero-length, or there was an encoding error.  In the latter
     * case, vstrlenf_verbose sets encoding_err to 1.
     */
    if ( encoding_err )
      return NULL;
    else
    {
      /*
       * We could return strdup("") here, but we'd have to #include <string.h>
       */
      if ( !(buf = malloc(1)) )
        return NULL;

      buf[0] = '\0';
      return buf;
    }
  }

  buf = malloc( size + 1 );

  if ( !buf )
    return NULL;

  vsprintf( buf, fmt, args );

  return buf;
}

size_t strlenf( const char *fmt, ... )
{
  va_list args;
  int result;
  char buf;

  va_start( args, fmt );
  /*
   * vsnprintf returns the number of chars that could
   * not be printed due to size limit.  So we call it
   * with size limit 0 to get the desired length.
   * (vsnprintf returns a negative number in case of encoding
   * error).
   */
  result = vsnprintf( &buf, 0, fmt, args );
  va_end( args );

  /*
   * In case of encoding error, vsnprintf returns a negative
   * number.  In that event, return 0.
   */
  if ( result < 0 )
    return 0;
  else
    return result;
}

size_t vstrlenf( const char *fmt, va_list args )
{
  char buf;
  int result;

  /*
   * vsnprintf returns the number of chars that could
   * not be printed due to size limit.  So we call it
   * with size limit 0 to get the desired length.
   * (vsnprintf returns a negative number in case of encoding
   * error).
   */
  result = vsnprintf( &buf, 0, fmt, args );

  /*
   * In case of encoding error, return 0.
   */
  if ( result < 0 )
    return 0;
  else
    return result;
}

size_t vstrlenf_verbose( const char *fmt, va_list args, int *err )
{
  char buf;
  int result;

  /*
   * vsnprintf returns the number of chars that could
   * not be printed due to size limit.  So we call it
   * with size limit 0 to get the desired length.
   * (vsnprintf returns a negative number in case of encoding
   * error).
   */
  result = vsnprintf( &buf, 0, fmt, args );

  /*
   * In case of encoding error, return 0 and indicate the
   * encoding error using a supplied int (if any).
   */
  if ( result < 0 )
  {
    if ( err )
      *err = 1;

    return 0;
  }
  else
    return result;
}
