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
AX_PKG_SWIG(2.0.1, [ ], [ AC_MSG_ERROR([SWIG is required.]) ] )
#AX_SWIG_PYTHON

dnl Which platform are we building on?
PLATFORM=
SHLIBSUFFIX=
case "`uname -s`" in
        Linux)  PLATFORM=linux
                SHLIBSUFFIX="so"
        ;;
        Darwin) PLATFORM=darwin
                SHLIBSUFFIX="dylib"
        ;;
        *)      PLATFORM=unknown
                SHLIBSUFFIX="so"
        ;;
esac
AC_SUBST(PLATFORM)
AC_SUBST(SHLIBSUFFIX)

#
# Java
#
# Ah the black art of building Java JNI code via SWIG with Autotools.  libkml is a 
# decent example.
#

# Where can we find the Java headers and libs?
AC_ARG_WITH(java-include-dir,
	[--with-java-include-dir=DIR search DIR for Java headers],
	[JAVA_INCLUDE_DIR=$withval],)
AC_SUBST(JAVA_INCLUDE_DIR)
AC_ARG_WITH(java-lib-dir,
	[--with-java-lib-dir=DIR search DIR for Java libraries],
	[JAVA_LIB_DIR=$withval],)
AC_SUBST(JAVA_LIB_DIR)


# Build Java SWIG bindings?
if test "x$SWIG" != x; then
    AC_ARG_ENABLE(java,
          [AS_HELP_STRING([--disable-java],
                          [do not generate Java SWIG bindings])])

    if test "x$enable_java" != xno; then
        AC_CHECK_PROG(JAVA, java, java, nojava)
        if test "$JAVA" = "nojava"; then
            AC_MSG_ERROR([no java binary in PATH])
        fi
        AC_CHECK_PROG(JAVAC, javac, javac, nojavac)
        if test "$JAVAC" = "nojavac"; then
            AC_MSG_ERROR([no javac binary in PATH, bindings will not be built])
        fi
        AC_CHECK_PROG(JAR, jar, jar, nojar)
        if test "$JAR" = "nojar"; then
            AC_MSG_ERROR([no jar binary in PATH, bindings will not be built])
        fi
        if test "x$JAVA" != x; then
            current_CPPFLAGS="$CPPFLAGS"
            if test "$CPPFLAGS" != ""; then
                CPPFLAGS="-I$current_CPPFLAGS -I$JAVA_INCLUDE_DIR -I$JAVA_INCLUDE_DIR/$PLATFORM"
            else
                CPPFLAGS="-I$JAVA_INCLUDE_DIR -I$JAVA_INCLUDE_DIR/$PLATFORM"
            fi

            AC_CHECK_HEADER(jni.h,,
                    [AC_MSG_WARN([could not find jni.h. The Java bindings will not be built.])
                    JAVA=
                    ])
            CPPFLAGS="$current_CPPFLAGS"
        fi
    fi
fi

AM_CONDITIONAL(WITH_JAVA, [test "x$JAVA" != x])

# Do it.
AC_OUTPUT

# vim: ts=8 et sw=4 sts=4
