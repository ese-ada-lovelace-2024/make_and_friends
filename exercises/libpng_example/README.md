This example uses the C library.

Try to write a Makefile/CMakeList.txt set up to build an executable called pngtest.

On the docker version, the library files are installed under /usr/include/ and /usr/lib, which are automatically in the search path, you just need to make sure that you tell the compiler to include the library.