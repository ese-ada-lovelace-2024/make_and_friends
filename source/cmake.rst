*************
Configuration
*************

Introduction
============

When building new software (or existing software on a new platform), often one of the hardest tasks is finding header files and libraries belonging to the other prerequisite software on which it depends.

For software with a proper build system this is often taken care of in a separate configuration step, using a configuration tool such as an autotools configure script, or CMake.


GNU autotools
=============

The GNU Autotools package is made up of a number of separate executables which together generate a set of Makefiles to build a code based on the contents of a number of templates, by substituing placeholder variables with the real paths and values.

While there are (and will continue to be) many autotools based packages out there in the wild, unless 

GNU Autoconf
------------

Autoconf processes a (vaguely) human-readable configure.ac file into a shell ``configure`` script which probes the local system to find executables, include paths and libraries. The configure script, when run, scans the build environment and generates another script which, in turn, converts Makefile.in templates into proper Makefiles for the system. Finally, running ``make`` compiles the code into the target product.

To quote the Wikipedia autoconf page:

    - If a source code file is changed then it suffices to re-run make, which only re-compiles that part of the body of the source code affected by the change.
    - If a .in file has changed then it suffices to re-run config.status and make.
    - If the body of source code is copied to another computer then it is sufficient to re-run configure (which runs config.status) and make. (For this reason source code using Autotools is normally distributed without the files that configure generates.)
    - If the body of source code is changed more fundamentally, then configure.ac and the .in files need to be changed and all subsequent steps also followed.
    - To process files, autoconf uses the GNU implementation of the m4 macro system.

GNU Automake
------------

Automake helps to create portable Makefiles, which are in turn processed with the make utility. It takes its input as Makefile.am, and turns it into Makefile.in, which is used by the configure script to generate the file Makefile output. It also performs automatic dependency tracking; every time a source file is compiled, the list of dependencies (e.g., C header files) is recorded. Later, any time make is run and a dependency appears to have changed, the dependent files will be rebuilt.




CMake
=====

CMake is a more recent development, originally developed at the company KitWare (who also develop VTK, the visualization toolkit and ParaView a 3D data viusualizer).

Compared to ``autotools``, CMake has a slightly cleaner structure, with a single tool, ``cmake`` which again processes text files to generate a system of Makefiles, which you then process to actually build your code.

CMakeLists.txt
--------------

At its most basic, a CMake configured project needs just one extra file, called ``CMakeLists.txt``. This contains the instructions necessary to build the code. A trivial example might look like the following ::

    # set the project name (and the name f)
    project(HelloWorld)

    # add the executable
    add_executable(hello hello_world.cpp)

We can ask cmake to process this file by navigating to the directory which contains it, then running.




CTest
-----


Further reading
===============

