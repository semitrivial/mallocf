#include <stdio.h>
#include "mallocf.h"

int main( int argc, const char* argv[] )
{
  char *world = "World";
  char *buf;
  size_t len;

  buf = strdupf( "Hello, %s!\n", world );

  printf( "%s", buf );

  len = strlenf( "%d+%f", 5, 3.14 );

  printf( "The length of the string \"%d+%f\" is %zd.\n", 5, 3.14, len );

  printf( "The result of "
          "strlenf(\"%%lc\", (wchar_t)-1)"
          " is %d, because that is an encoding error.\n",
          strlenf("%lc", (wchar_t)-1) );

  return 1;
}
