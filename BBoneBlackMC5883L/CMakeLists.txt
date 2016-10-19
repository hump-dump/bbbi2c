cmake_minimum_required ( VERSION 2.6 )

SET( CMAKE_CXX_FLAGS "-std=c++0x" )

set( LIBSRC BBoneBlackMC5883L.cpp )

add_library( mc5883l SHARED ${LIBSRC} )
add_library( mc5883l_static STATIC ${LIBSRC} )

set_target_properties( mc5883l_static PROPERTIES OUTPUT_NAME mc5883l )

install (TARGETS mc5883l DESTINATION lib )
install (FILES BBoneBlackMC5883L.hpp DESTINATION include )