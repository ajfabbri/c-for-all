/**
 * libcforall: SWIG (and autotools) skeleton library.
 *
 * Includes sample code to demonstrate simple function calls from other
 * ("scripting") languages to C.
 *
 * See ../LICENSE. (c) Aaron Fabbri, 2014.
 */

#include <string.h>

#include "libforall.h"

struct opaque_thingy {
    int x;
    double y;
}

/* Some arbitrary values to pass around. */
#define THINGY_VAL              { .a = 22, .b = 9990 }
#define OPAQUE_THINGY_VAL       { .x = -100, .y = 3.14159 }

static const struct thingy thingy_constant = THINGY_VAL;
static const struct opaque_thingy opaque_thingy_constant = OPAQUE_THINGY_VAL;

/**
 * Return a string consisting of the character 'c' repeated 'count' times.
 * TODO who owns allocation?  Do we malloc then provide a free() function for
 * script?
*/
char * repeatChar(char c, int count)
{
    char *s = malloc(count);
    memset(s, (unsigned char)c, count);
    return s;
}

double multiply(double x, double y)
{
    return x * y;
}

struct thingy * get_thingy(void)
{ 
    struct thingy *t;
    t = malloc(sizeof(*t));
    t = THINGY_VAL;
    return t;
}

int is_thingy_valid(const struct thingy *t)
{
    if (t.a == thingy_constant.a && t.b == thingy_constant.b)
        return 1;
    else
        return 0;
}

struct opaque_thingy * get_opaque_thingy(void)
{
    struct thingy *t;
    t = malloc(sizeof(*t));
    t = THINGY_VAL;
    return t;
}

int is_opaque_thingy_valid(const struct opaque_thingy *)
{
    if (t.x == opaque_thingy_constant.a && t.y == opaque_thingy_constant.b)
        return 1;
    else
        return 0;
}

// vim: sw=4 sts=0 et
