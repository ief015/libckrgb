libckrgb
========

Script your Corsair keyboard's RGB lights just the way you want them.
libckrgb is an open, free, and cross-platform C library that only depends on the [libusb](http://www.libusb.org/) library.

Documentation is a work in progress and is currently not available. However, you may check out the `sample.cpp` file for a bunch of small examples on how to use the library.

Including in your project
-------------------------

Simply link the linkable library into your project and include the header: `#include <ckrgb/libckrgb.h>`

Alternatively, if you're using C++: `#include <ckrgb/libckrgb.hpp>`

and you're done!

If you are linking with a staticly-linked library, you must add the preprocessor define `CKRGB_STATIC`.

Some precompiled builds have been provided under the `builds` folder of this project.

Compiling
---------

libckrgb is written in C and only depends on [libusb-1.0](http://www.libusb.org/).

When building, you must add the preprocessor define CKRGB_BUILD. If you're building a staticly-linked library, you must also add CKRGB_STATIC to the define list.

Credits
-------

Many thanks to [/u/CalcProgrammer1](http://www.reddit.com/user/CalcProgrammer1/) for reverse engineering the lighting protocol and to [LibCorsairRGB by Palmr](http://github.com/Palmr/LibCorsairRGB).