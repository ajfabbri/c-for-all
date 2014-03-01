c-for-all
=========

Example C library callable from Java, Python, and other languages.

Motivation
----------

I want a skeleton or template library that:

- Is implemented in C.
- Uses Autotools / Gnu Make to build.
- Is callable from Java, Python, and other languages.
- Uses SWIG to create bindings for other languages.

Dependencies
------------
- Autotools  (install autotools-dev, automake, libtool, autoconf)
- Install swig 2.
	e.g. on Debian/Ubuntu, `apt-get install swig2.0`
	on OS X, with homebrew, `brew install swig`


How To Build
------------

1. Clone this repository.

2. Generate build files:

```
  ./autogen.sh
```

3. 

```
 $ mkdir build && cd build
 $ ../configure --with-java-include-dir=$JAVA_HOME/include --with-java-lib-dir=$JAVA_HOME/lib
 $ make
```

*Set your JAVA_HOME environment variable.*
On Debian/Ubuntu I'm using /usr/lib/jvm/java-7-oracle 
On OS X you can usually use the output of the command `/usr/libexec/java_home`,
e.g. in your .bashrc
```
  export JAVA_HOME=`/usr/libexec/java_home`
```


Running Example
---------------

To test calling the library from Java:

```
 $ cd src/test/java
 $ ./run_test.sh
 ```

The script builds and runs and example Java app that calls the C library.  Woo hoo.

Other Thoughts
--------------

See also ./TODO.

Libkml is a good example with nice documentation.  Eventually the process for
building various language bindings should be similar:

https://code.google.com/p/libkml/wiki/BuildingAndInstalling
