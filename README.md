# mallocf: A library for allocating formatted strings.

## License: MIT.

## Features

* Reentrant
* Does not depend on static buffers
* Provides the following functions (see documentation below):
  * `strdupf`
  * `strlenf`
  * `vstrdupf`
  * `vstrlenf`

## Installation

1. Add `mallocf.c` and `mallocf.h` to your project as if you wrote them
yourself.
2. `#include "mallocf.h"` in any file where you want to use mallocf
functions.

## Documentation

### `strdupf`

> `char *strdupf( const char *fmt, ... );`

Returns a `C` string obtained by applying a format (`fmt`) to a variadic list
of parameters (`...`).  Like `printf`, but printing to memory instead of screen.
The string is `malloc`'d, and should be `free`'d when no longer needed.
Returns `NULL` if the necessary memory couldn't be allocated (or if the format
is prevented by an encoding error caused by mixing wide chars and non-wide chars).

#### Example

> `char *x = strdupf( "Hello %s", world_name );`

### `strlenf`

> `size_t strlenf( const char *fmt, ... );`

Returns the length of a `C` string obtained by applying a format (`fmt`) to
a variadic list of parameters (`...`).  Returns 0 if there is
an encoding error caused by mixing wide chars and non-wide chars.

#### Example

> `size_t len = strlenf( "The value of pi is %f", pi );`

### `vstrdupf`

> `char *vstrdupf( const char *fmt, va_list args );`

Returns a `C` string obtained by applying a format (`fmt`) to a `va_list`
of arguments.  Like `vprintf`, but prints to memory instead of screen.
Returns a `malloc`'d string, which should be `free`'d when no longer needed.
Returns `NULL` if the necessary memory could not be allocated (or if the
format is prevented by an encoding error caused by mixing wide and non-wide
chars).

### `vstrlenf`

> `size_t vstrlenf( const char *fmt, va_list args );`

Returns the length of a `C` string obtained by applying a format (`fmt`) to
a `va_list` of arguments.  Returns 0 if there is an encoding error caused by
mixing wide and non-wide chars.
