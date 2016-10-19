cmake_minimum_required ( VERSION 2.6 )

project( GY801 )
SET( CMAKE_CXX_FLAGS "-std=c++0x" )

add_subdirectory( BBoneBlackI2C )
add_subdirectory( BBoneBlackMC5883L )
add_subdirectory( BBoneBlackBMP085 )

add_executable( gy801 main.cpp )

target_link_libraries( gy801 STATIC bbbi2c bmp085 mc5883l )