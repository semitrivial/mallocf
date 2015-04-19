# mallocf: A library for allocating formatted strings.

## License: MIT.

## Features: Reentrant, does not depend on static buffers etc.

Functions:
*`strdupf`
*`strlenf`
*`vstrdupf`
*`vstrlenf`

## Installation

Simply add `mallocf.c` and `mallocf.h` to your project as if you wrote them
yourself.  `#include "mallocf.h"` in any file where you want to use mallocf
functions.

## Documentation

### `strdupf`

> `char *strdupf( const char *fmt, ... );`

Returns a `C` string obtained by applying a format (`fmt`) to a variadic list
of parameters (`...`).  Like `printf`, but printing to memory instead of screen.
The string is `malloc`'d, and should be `free`'d when no longer needed.
Returns `NULL` if the necessary memory couldn't be allocated.

#### Example

> `char *x = strdupf( "Hello %s", world_name );`

### `strlenf`

> `size_t strlenf( const char *fmt, ... );`

Returns the length of a `C` string obtained by applying a format (`fmt`) to
a variadic list of parameters (`...`).  

#### Example

> `size_t len = strlenf( "%d+%f", id_number, pi );`

### `vstrdupf`

> `char *vstrdupf( const char *fmt, va_list args );`

Returns a `C` string obtained by applying a format (`fmt`) to a `va_list`
of arguments.  Like `vprintf`, but prints to memory instead of screen.
Returns a `malloc`'d string, which should be `free`'d when no longer needed.
Returns `NULL` if the necessary memory could not be allocated.

### `vstrlenf`

> `size_t vstrlenf( const char *fmt, va_list args );`

Returns the length of a `C` string obtained by applying a format (`fmt`) to
a `va_list` of arguments.
