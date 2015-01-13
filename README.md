libckrgb 0.1 alpha
==================

Script your Corsair keyboard's RGB lights just the way you want them.
libckrgb is an open, free, and cross-platform C library that only depends on the [libusb](http://www.libusb.org/) library.

Documentation is a work in progress and is currently not available. However, you may check out the `sample.cpp` file for a bunch of small examples on how to use the library.

Compiling
---------

libckrgb is written in C and only depends on [libusb-1.0](http://www.libusb.org/).

Use [CMake](http://www.cmake.org/) to compile under the IDE of your choice.

When generating under CMake, you must define the include and library directories for libusb by setting options `LIBUSB_INCLUDE_DIR` and `LIBUSB_LIB_DIR` respectively. The `LIBUSB_LIB_FILE` option may have to be modified to match the correct object file.

Enable `CKRGB_BUILD_STATIC_LIB` under CMake if you wish to build libckrgb as a staticly-linked library.


Including in your project
-------------------------

Simply include the `include` directory for libckrgb and link the linkable library into your project. Then, you may include the header in your project like so: `#include <ckrgb/libckrgb.h>`

Alternatively, if you're using C++: `#include <ckrgb/libckrgb.hpp>`

and you're done!

If you are linking with a staticly-linked library, you must add the preprocessor define `CKRGB_STATIC` to your project.

Some precompiled builds for libckrgb have been provided under the `builds` folder of this project.

Credits
-------

Written in C by Nathan Cousins.

Many thanks to [/u/CalcProgrammer1](http://www.reddit.com/user/CalcProgrammer1/) for reverse engineering the lighting protocol and to [LibCorsairRGB by Palmr](http://github.com/Palmr/LibCorsairRGB).