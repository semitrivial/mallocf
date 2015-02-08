mallocf: A library for allocating formatted strings.  License: MIT.

Features: Does not depend on static buffers etc.

Functions:  strdupf, strlenf, vstrdupf, vstrlenf

(Q: "What about strcpyf and strncpyf?"  A: "Use sprintf or snprintf!")

------------

Examples:

Allocate a formatted string:
char *x = strdupf( "Hello %s", world_name );

Calculate tricky lengths e.g. length of int, length of float...
size_t len = strlenf( "%d+%f", id_number, pi );
