cmake_minimum_required ( VERSION 2.6 )

project( GY801 )

SET( CMAKE_INSTALL_PREFIX=../install )

add_subdirectory( BBoneBlackI2C )
add_subdirectory( BBoneBlackMC5883L )
add_subdirectory( BBoneBlackBMP085 )

add_executable( gy801 main.cpp )
