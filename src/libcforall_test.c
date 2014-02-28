/**
 * Test for SWIG (and autotools) skeleton library.
 * See ../LICENSE. (c) Aaron Fabbri, 2014.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "libcforall.h"

int main(int argc, char *argv[])
{

    printf("%s: testing libcforall.\n", __func__);
    char *s = repeat_char('a', 20);
    assert(strlen(s) == 20);
    printf("%s\n", s);
    free(s);

    struct opaque_thingy *ot = get_opaque_thingy();
    assert(is_opaque_thingy_valid(ot));
    free(ot);

    struct thingy *t = get_thingy();
    printf("Thingy t.a = %d, t.b = %d\n", t->a, t->b);
    assert(is_thingy_valid(t));
    free(t);

    double x = 100.0, y = 37;
    printf("multiply(%f, %f) -> %f\n", x, y, multiply(x, y));
    assert(x * y == multiply(x, y));

    return EXIT_SUCCESS;
}

// vim: ts=8 et sw=4 sts=4
