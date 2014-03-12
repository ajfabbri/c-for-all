/**
 * libcforall: SWIG (and autotools) skeleton library.
 * See ../LICENSE. (c) Aaron Fabbri, 2014.
 */

#ifndef _LIBCFORALL_H_
#define _LIBCFORALL_H_

unsigned long rdtscl(void);
double get_cycles_per_usec(void);

/* nonsense (testing) functions below */
struct thingy {
    int a;
    int b;
};

struct opaque_thingy;

char * repeat_char(char c, int count);
double multiply(double x, double y);

struct thingy * get_thingy(void);
int is_thingy_valid(const struct thingy *);

struct opaque_thingy * get_opaque_thingy(void);
int is_opaque_thingy_valid(const struct opaque_thingy *);

#endif /* _LIBCFORALL_H_ */

// vim: sw=4 sts=0 et
