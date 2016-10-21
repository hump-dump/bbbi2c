cmake_minimum_required ( VERSION 2.6 )

SET( CMAKE_CXX_FLAGS "-std=c++0x" )
add_compile_options( -D_GLIBCXX_USE_CXX11_ABI=1 )
SET( CFLAGS -msoft-float -D__GCC_FLOAT_NOT_NEEDED -march=armv4t -mtune=arm920t )

set( LIBSRC BBoneBlackMC5883L.cpp )

add_library( mc5883l STATIC ${LIBSRC} )

link_libraries( bbbi2c )

install (TARGETS mc5883l DESTINATION lib )
install (FILES BBoneBlackMC5883L.hpp DESTINATION include )