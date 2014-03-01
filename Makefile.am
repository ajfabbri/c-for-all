
# See
# http://www.gnu.org/software/automake/manual/html_node/A-Shared-Library.html#A-Shared-Library

ACLOCAL_AMFLAGS = -I config
AM_CFLAGS = -I$(srcdir)/src/include -g -Wall

#
# C Shared Lib
#
lib_LTLIBRARIES = src/libcforall.la
src_libcforall_la_SOURCES = src/libcforall.c
#src_libcforall_la_LDFLAGS = -lother-dependency-lib
src_libcforallincludedir = src/include/libcforall.h
include_HEADERS = src/include/libcforall.h

#
# Test program(s)
#
bin_PROGRAMS = libcforall_test 
libcforall_test_SOURCES = src/libcforall_test.c
libcforall_test_LDADD = src/libcforall.la

pkglib_LTLIBRARIES =

#
# Java
#
if WITH_JAVA
pkglib_LTLIBRARIES += src/libcforall_java.la

java_package_dir = src/net/fabbrication/cforall
src_libcforall_java_la_SOURCES = src/cforall_java.c
src_libcforall_java_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(JAVA_INCLUDE_DIR) \
    -I$(JAVA_INCLUDE_DIR)/$(PLATFORM)
src_libcforall_java_la_LIBADD = $(top_builddir)/src/libcforall.la

src/cforall_java.c: src/swig/cforall.i
	mkdir -p $(java_package_dir) 
	$(SWIG) $(AM_CPPFLAGS) -java -o src/cforall_java.c \
	-package net.fabbrication.cforall \
	-outdir $(java_package_dir) $(top_srcdir)/src/swig/cforall.i

javadir = $(datadir)/java
java_DATA = cforall.jar
cforall.jar : src/cforall_java.c
	$(JAVAC) $(java_package_dir)/*.java
	$(JAR) cf cforall.jar $(java_package_dir)/*.class

dist-hook: cforall.jar
	cp -p -v $(top_builddir)/src/swig/cforall.jar $(distdir)/
endif

EXTRA_DIST = README LICENSE TODO \
	cforall.i
# vim: ts=8 sw=8
