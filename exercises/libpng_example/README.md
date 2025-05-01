This example by Guillaume Cottenceau and Yoshimasa Niwa uses an external C library (libpng) to produce image files.

Try to write a Makefile or CMakeList.txt file which is set up to build an executable called pngtest.

On the docker/.devcontainer version, the libpng library files are installed under the directories `/usr/include/` (for the header files) and `/usr/lib` (for the actual `libpng.so` dynamic library), which are automatically in the search path, so here you just need to make sure that you tell the compiler to include the library.

On Mac, you can install libpng using Homebrew with the command:

```bash
brew install libpng
```

On Ubuntu/WSL, you can install libpng using the command:

```bash
sudo apt-get install libpng-dev
```

On native Windows, you can install libpng by downloading the precompiled binaries from the official website: http://www.libpng.org/pub/png/libpng.html. Try to remember where you downloaded the files, as you will need to add the path to the header files and the library files to your compiler's search path, either in your hand-written Makefile or in the CMakeLists.txt file.