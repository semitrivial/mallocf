#include <stdio.h>
#include "mallocf.h"

int main( void )
{
  char *world = "World";
  char *buf;

  buf = strdupf( "Hello, %s!\n", world );

  printf( "%s", buf );

  printf( "The length of the string \"%d+%f\" is %d.\n",
          5, 3.14, strlenf( "%d+%f", 5, 3.14 ) );

  return 1;
}
