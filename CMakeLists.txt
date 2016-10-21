cmake_minimum_required ( VERSION 2.6 )

project( GY801 )
SET( CMAKE_CXX_FLAGS "-std=c++0x --sysroot=D:/SysGCC/Beaglebone/arm-linux-gnueabihf/sysroot" )
#add_compile_options( -D_GLIBCXX_USE_CXX11_ABI=1 )
SET( CMAKE_EXE_LINKER_FLAGS "-static" )
#SET( CFLAGS -msoft-float -D__GCC_FLOAT_NOT_NEEDED -march=armv4t -mtune=arm920t )

add_subdirectory( BBoneBlackI2C )
add_subdirectory( BBoneBlackMC5883L )
add_subdirectory( BBoneBlackBMP085 )

add_executable( gy801 main.cpp )

target_link_libraries( gy801 bbbi2c bmp085 mc5883l )
install (TARGETS gy801 DESTINATION bin )
