#!/bin/bash

# Where the shared libs are built
SHARED_LIB_PATH=../../../build/src/.libs
CLASS_PATH=.:../../build/src/swig

set -x

export LD_LIBRARY_PATH=$SHARED_LIB_PATH
export DYLD_LIBRARY_PATH=$SHARED_LIB_PATH       # OS X

rm -f *.class

javac -classpath $CLASS_PATH JavaToC.java

