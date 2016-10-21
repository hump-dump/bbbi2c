cmake_minimum_required ( VERSION 2.6 )

SET( CMAKE_CXX_FLAGS "-std=c++0x" )
add_compile_options( -D_GLIBCXX_USE_CXX11_ABI=1 )

set( LIBSRC CPBBoneBlackI2C.cpp )

add_library( bbbi2c STATIC ${LIBSRC} )

install (TARGETS bbbi2c DESTINATION lib )
install (FILES CPBBoneBlackI2C.hpp DESTINATION include )