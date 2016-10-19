cmake_minimum_required ( VERSION 2.6 )

project( GY801 )

SET( CMAKE_INSTALL_PREFIX=../install )

add_subdirectory( BBoneBlackI2C )

add_executable( gy801 main.cpp BBoneBlackMC5883L.cpp  BBoneBlackBMP085.cpp )

target_link_libraries( gy802 bbbi2c )
