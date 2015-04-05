#ifndef MALLOCF_INCLUDE_GUARD
#define MALLOCF_INCLUDE_GUARD

#include <string.h>
#include <stdarg.h>
#include <ctype.h>

char *strdupf( const char *fmt, ... );
char *vstrdupf( const char *fmt, va_list args );
size_t strlenf( const char *fmt, ... );
size_t vstrlenf( const char *fmt, va_list args );

/*
 * The magical __MALLOCF_IF_NONVOID macro (which requires some work to define):
 *   1. '__MALLOCF_IF_NONVOID(type,code)' expands to 'code' if 'type' is not 'void'
 *   2. '__MALLOCF_IF_NONVOID(void,code)' expands to nothing.
 *
 * Example of the kind of macro you can build using IF_NONVOID:
 *   #define APPLY_AND_RETURN(fnc,type,...)\
 *     __MALLOCF_IF_NONVOID(type,return) fnc(__VA_ARGS__);
 *
 * would expand as follows:
 * APPLY_AND_RETURN(printf,void,"Hi") expands to:  printf("Hi");
 * APPLY_AND_RETURN(strdup,char*,size) expands to:  return strdup(size);
 * APPLY_AND_RETURN(strdup,void*,size) expands to:  return strdup(size);
 * APPLY_AND_RETURN(strdup,void,size) expands to:  strdup(size);
 */

#define __MALLOCF_CAT(a,...) __MALLOCF_CAT_(a,__VA_ARGS__)
#define __MALLOCF_CAT_(a,...) a ## __VA_ARGS__
#define __MALLOCF_IF_NONVOID_WORKERvoid(...) ,
#define __MALLOCF_EVAL_SECOND_PARAM(a,b,...) b
#define __MALLOCF_EVAL(...) __VA_ARGS__
#define __MALLOCF_BLANK

#define \
__MALLOCF_IF_NONVOID(type,code)\
__MALLOCF_EVAL\
(\
  __MALLOCF_EVAL_SECOND_PARAM\
  __MALLOCF_BLANK\
  (\
    __MALLOCF_CAT(__MALLOCF_IF_NONVOID_WORKER,type)(),\
    code\
  )\
)

#define LAST_ARG2(

#endif
