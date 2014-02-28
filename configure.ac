AC_PREREQ([2.67])
AC_INIT([libcforall], [1.0], [ajfabbri@gmail.com])
AC_CONFIG_SRCDIR([src/libcforall.c])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR(config)
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

# We're using libtool to help with shared libs 
AM_PROG_AR
LT_INIT

# Check for other programs
AC_PROG_CC

# SWIG
AX_PKG_SWIG(2.0.1, [], AC_MSG_ERROR([SWIG is required.]) )
AX_SWIG_ENABLE_CXX
AX_SWIG_MULTI_MODULE_SUPPORT
AX_SWIG_PYTHON

AC_OUTPUT
