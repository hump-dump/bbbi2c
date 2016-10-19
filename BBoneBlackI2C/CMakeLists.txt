cmake_minimum_required ( VERSION 2.6 )

SET( CMAKE_CXX_FLAGS "-std=c++0x" )

set( LIBSRC CPBBoneBlackI2C.cpp )

add_library( bbbi2c SHARED ${LIBSRC} )
add_library( bbbi2c_static STATIC ${LIBSRC} )

set_target_properties( bbbi2c_static PROPERTIES OUTPUT_NAME bbbi2c )

install (TARGETS bbbi2c DESTINATION lib )
install (FILES CPBBoneBlackI2C.hpp DESTINATION include )