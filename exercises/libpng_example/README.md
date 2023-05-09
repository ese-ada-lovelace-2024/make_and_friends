This example by Guillaume Cottenceau and Yoshimasa Niwa uses an external C library (libpng) to produce image files.

Try to write a Makefile or CMakeList.txt file which is set up to build an executable called pngtest.

On the docker/.devcontainer version, the libpng library files are installed under the directories `/usr/include/` (for the header files) and `/usr/lib` (for the actual `libpng.so` dynamic library), which are automatically in the search path, so here you just need to make sure that you tell the compiler to include the library.