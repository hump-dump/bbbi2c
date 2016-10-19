cmake_minimum_required ( VERSION 2.6 )

SET( CMAKE_CXX_FLAGS "-std=c++0x" )

set( LIBSRC BBoneBlackBMP085.cpp )

add_library( bmp085 SHARED ${LIBSRC} )
add_library( bmp085_static STATIC ${LIBSRC} )

set_target_properties( bmp085_static PROPERTIES OUTPUT_NAME bmp085 )

install (TARGETS bmp085 DESTINATION lib )
install (FILES BBoneBlackBMP085.hpp DESTINATION include )