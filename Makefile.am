EXTRA_DIST = README LICENSE TODO

# See
# http://www.gnu.org/software/automake/manual/html_node/A-Shared-Library.html#A-Shared-Library

ACLOCAL_AMFLAGS = -I config
AM_CFLAGS = -I$(srcdir)/include -g -Wall

#
# C Shared Lib
#
lib_LTLIBRARIES = src/libcforall.la
src_libcforall_la_SOURCES = src/libcforall.c
#src_libcforall_la_LDFLAGS = 
src_libcforallincludedir = include/libcforall.h
include_HEADERS = include/libcforall.h

#
# Test program(s)
#
bin_PROGRAMS = libcforall_test 
libcforall_test_SOURCES = src/libcforall_test.c
libcforall_test_LDADD =  src/libcforall.la
