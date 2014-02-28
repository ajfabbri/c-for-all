EXTRA_DIST = README LICENSE TODO

# See
# http://www.gnu.org/software/automake/manual/html_node/A-Shared-Library.html#A-Shared-Library

#
# C Shared Lib
#
lib_LTLIBRARIES = src/libcforall.la
src_libcforall_la_SOURCES = src/libcforall.c
#src_libcforall_la_LDFLAGS = 
# include_HEADERS = < any other public headers users will need >

#
# Test program(s)
#
bin_PROGRAMS = libcforall_test 
libcforall_test_SOURCES = src/libcforall_test.c
libcforall_test_LDADD =  src/libcforall.la
