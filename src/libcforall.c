/**
 * libcforall: SWIG (and autotools) skeleton library.
 *
 * Includes sample code to demonstrate simple function calls from other
 * ("scripting") languages to C.
 *
 * See ../LICENSE. (c) Aaron Fabbri, 2014.
 */
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#include "libcforall.h"

/*
 * Fun things you always wanted to do from other languages. 
 */

/** Read 64-bit CPU Time Stamp Counter. */
unsigned long rdtscl(void)
{
    unsigned int l, h;
    asm volatile("rdtsc" : "=a" (l), "=d" (h));
    return l | (((unsigned long)h) << 32);
}

/** Put some load on cpu to come out of sleep states. */
static void load_cpu(void)
{
    unsigned long count = 0;
    unsigned long i;
    const unsigned int log2_iter = 10;
    /* Code does nothing useful except trick gcc to not optimize it out. */
    for (i = 0; i < (1<<log2_iter); i++) {
        if ((i & 0x111) == i)
            i++;
        if (i > i%19)
           usleep(0); 
    }
}

/** Determine cpu ticks per microsecond. */
double get_cycles_per_usec(void)
{
    unsigned long pre, post;
    struct timespec start_t, end_t;
    unsigned long tsc_start, tsc_end;
    double elapsed;
    int i;

    load_cpu();

    /* read timestamp counter before and after getting wall time */
    pre = rdtscl();
    clock_gettime(CLOCK_MONOTONIC, &start_t);
    post = rdtscl();
    /* average timestamps */
    tsc_start = ((double)pre + (double)post)/2;

    /* pass some time burning CPU */
    for (i = 0; i<10; i++)
        load_cpu();

    /* get another reading */
    pre = rdtscl();
    clock_gettime(CLOCK_MONOTONIC, &end_t);
    post = rdtscl();
    tsc_end =((double)pre + (double)post)/2;

    /* get elapsed wall time */
    struct timespec delta;
    delta.tv_sec = end_t.tv_sec - start_t.tv_sec;
    delta.tv_nsec = end_t.tv_nsec - start_t.tv_nsec;
    /* handle nsec wrapping */
    if (delta.tv_nsec < 0) {
        delta.tv_nsec += 1e9;
        delta.tv_sec--;
    }

    /* In usec */
    elapsed = delta.tv_nsec / 1000 + delta.tv_sec * 1e6;
    return (tsc_end - tsc_start) / elapsed;
}

/*
 * Nonesense functions (for testing SWIG) below..............................
 */
struct opaque_thingy {
    int x;
    double y;
};


/* Some arbitrary values to pass around. */
#define THINGY_VAL          ((struct thingy){ .a = 22, .b = 9990 })
#define OPAQUE_THINGY_VAL   ((struct opaque_thingy){ .x = -100, .y = 3.14159 })

static const struct thingy thingy_constant = THINGY_VAL;
static const struct opaque_thingy opaque_thingy_constant = OPAQUE_THINGY_VAL;

/**
 * Return a string consisting of the character 'c' repeated 'count' times.
 * TODO who owns allocation?  Do we malloc then provide a free() function for
 * script?
*/
char * repeat_char(char c, int count)
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
    *t = THINGY_VAL;
    return t;
}

int is_thingy_valid(const struct thingy *t)
{
    if (t->a == thingy_constant.a && t->b == thingy_constant.b)
        return 1;
    else
        return 0;
}

struct opaque_thingy * get_opaque_thingy(void)
{
    struct opaque_thingy *t;
    t = malloc(sizeof(*t));
    *t = OPAQUE_THINGY_VAL;
    return t;
}

int is_opaque_thingy_valid(const struct opaque_thingy *t)
{
    if (t->x == opaque_thingy_constant.x && t->y == opaque_thingy_constant.y)
        return 1;
    else
        return 0;
}

// vim: ts=8 et sw=4 sts=4
