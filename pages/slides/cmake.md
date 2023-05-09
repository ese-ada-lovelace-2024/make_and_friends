# Configuration

https://ese-msc-2022.github.io/ppp-make/slides/cmake.html

j.percival@imperial.ac.uk



# Configuration

- One of the hardest tasks in building new software is finding header files/libraries for dependencies.

- In a proper build system this is dealt with in a configuration step, using a configuration tool such as an
autotools, or CMake.



## GNU autotools

- GNU Autotools package made up of a number of tools
which generate Makefiles from templates,substituing placeholder variables
with real paths and values.

- Many autotools packages out there, but probably best not to add to them.


Installation instructions typically look something like

```
./configure
make
sudo make install
```

`configure` script is bash script, built up from many macros.


### GNU Autoconf

- Autoconf processes  human-readable `configure.ac` file listing macros into `configure` script
- Probes the local system to find
executables, include paths and libraries.
- Generates another script which converts `Makefile.in` templates into Makefiles
- Running `make` compiles the code.


To quote the Wikipedia autoconf page:

> -   If a source code file is changed then it suffices to re-run make,
>     which only re-compiles that part of the body of the source code
>     affected by the change.
> -   If a .in file has changed then it suffices to re-run config.status
>     and make.


> -   If the body of source code is copied to another computer then it
>     is sufficient to re-run configure (which runs config.status) and
>     make. (For this reason source code using Autotools is normally
>     distributed without the files that configure generates.)


> -   If the body of source code is changed more fundamentally, then
>     configure.ac and the .in files need to be changed and all
>     subsequent steps also followed.


### GNU Automake, libtools etc.

Autotools has several other components:

- `automake` preprocesses `Makefile.am` files into and turns it
into `Makefile.in` files
- Autogenerates the list of dependencies.
- `libtool` generalises the building of libraries across systems.



## CMake

- CMake is newer (around 1999), developed at KitWare (also develop VTK, the visualization toolkit & ParaView, 3D data viusualizer).

- Compared to `autotools`, CMake has a slightly cleaner structure.

- single tool, `cmake` (or `cmake-gui`)
- processes text files to generate Makefiles
- cross-platform, including Windows


Build instructions look like

```bash
cmake .
make
sudo make install
```


### CMakeLists.txt

- CMake basically needs just one extra file,
called `CMakeLists.txt`.
- Contains the instructions necessary to
build the code.
- Includes list of source files for each target


A trivial example:

```cmake
# set the project name (maybe version number etc.)
project(HelloWorld)

# add the executable
add_executable(hello hello_world.cpp)
```



Usefulness comes from additional cmake macros, especially `find_package()`.

```
find_package(MPI REQUIRED)

target_link_libraries(hello PUBLIC MPI::MPI_CXX)
```


When CMake runs, it looks for the package (provided it knows about it) and sets up extra variables for you to use.



You can also create cmake variable (and set values or defaults) yourself.

Just use the `set` command to force a value
```
set(MY_VARIABLE "my value")
```

or to set a default
```
set(MY_VARIABLE "my value" CACHE STRING)
```


Default (a.k.a cache) variables can also be set on the command line or via a GUI (e.g Cmake-gui on windows/mac or ccmake on mac/linux)


### CTest

- CMake also includes its own generic testing framework.
- Allows you to build test suites for any supported language.
- Support for web dashboards to report results.
- Lets go look at some code.



## Further Reading

- [CMake homepage](https://cmake.org/)
- [CMake manual](https://cmake.org/cmake/help/v3.20/)
- [Offical tutorial](https://cmake.org/cmake/help/v3.20/guide/tutorial/index.html?highlight=tutorial)
