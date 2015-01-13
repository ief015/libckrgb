cmake_minimum_required(VERSION 2.8)
project( libckrgb )

macro(set_option var type default docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

#set_option( CKRGB_BUILD_LIB BOOL TRUE "TRUE to build libckrgb library" )
set_option( CKRGB_BUILD_STATIC_LIB BOOL FALSE "TRUE to build staticly-linked libckrgb library"  )
set_option( LIBUSB_INCLUDE_DIR PATH "" "Include directory for libusb" )
set_option( LIBUSB_LIB_DIR PATH "" "Binary lib directory for libusb" )
set_option( LIBUSB_LIB_FILE FILE "libusb-1.0.lib" "Binary lib object for libusb" )

#if( CKRGB_BUILD_LIB )
  add_definitions( -DCKRGB_BUILD )
  if( CKRGB_BUILD_STATIC_LIB )
    add_definitions( -DCKRGB_STATIC )
  endif()
#endif()

include_directories( ${LIBUSB_INCLUDE_DIR} )
link_directories(${LIBUSB_LIB_DIR})

include_directories( "libckrgb/include" )
add_subdirectory( "libckrgb/src" )