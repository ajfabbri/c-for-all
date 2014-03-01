#!/bin/bash

#
# Build and run JavaToC, a test which calls our example C lib.
#

# Where the shared libs are built
SHARED_LIB_PATH=../../../build/src/.libs
CLASS_PATH=.:../../../build/src

export LD_LIBRARY_PATH=$SHARED_LIB_PATH
export DYLD_LIBRARY_PATH=$SHARED_LIB_PATH       # OS X

set -x

rm -f *.class

javac -classpath $CLASS_PATH JavaToC.java

java -classpath $CLASS_PATH JavaToC
