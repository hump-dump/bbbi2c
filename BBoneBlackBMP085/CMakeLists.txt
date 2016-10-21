cmake_minimum_required ( VERSION 2.6 )

set( LIBSRC BBoneBlackBMP085.cpp )

add_library( bmp085 STATIC ${LIBSRC} )

link_libraries( bbbi2c )

install (TARGETS bmp085 DESTINATION lib )
install (FILES BBoneBlackBMP085.hpp DESTINATION include )
