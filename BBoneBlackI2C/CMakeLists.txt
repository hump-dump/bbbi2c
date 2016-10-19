cmake_minimum_required ( VERSION 2.6 )

SET( CMAKE_INSTALL_PREFIX=../install )
SET( CMAKE_CXX_FLAGS "-std=c++0x" )

add_library( bbbi2c SHARED STATIC
    CPBBoneBlackI2C.cpp 
)

install (TARGETS bbbi2c DESTINATION lib )
install (FILES CPBBoneBlackI2C.hpp DESTINATION include )