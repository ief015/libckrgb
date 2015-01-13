set( CKRGB_SRCS
  libckrgb.c
  keyboard.c
)

if( ${CKRGB_BUILD_STATIC_LIB} )
  add_library( libckrgb STATIC ${CKRGB_SRCS} )
else()
  add_library( libckrgb SHARED ${CKRGB_SRCS} )
endif()

target_link_libraries( libckrgb ${LIBUSB_LIB_DIR}/${LIBUSB_LIB_FILE} )