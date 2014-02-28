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
- Autotools 
- Install swig 2.
	e.g. on Debian/Ubuntu, `apt-get install swig2.0`
	on OS X, with homebrew, `brew install swig`


How To Build
------------

1. Clone this repository.
2. Generate build files:

 $ ./autogen.sh

3. ./configure && make

