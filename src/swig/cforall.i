%module libcforall
%{
/* Include c lib's public header in wrapper code. */
#include "libcforall.h"

/* Parse header to generate wrappers. */
%include "libcforall.h"

%}


