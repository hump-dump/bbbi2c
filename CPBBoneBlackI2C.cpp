#include "CPBBoneBlackI2C.hpp"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <iostream>
#include "CPDebugMessage.hpp"

using namespace std;

eResult CPBBoneBlackI2C::setDeviceName( const std::string & deviceName )
{
   mI2CDevice = deviceName;
}

bool CPBBoneBlackI2C::openDevice()
{
   debug( "openDevice " + mI2CDevice );

   bool result = false;

   mI2CHandle = open( mI2CDevice.c_str(), O_RDWR );
   if( 0 > mI2CHandle ) {
      debug( "can't open i2c device " + mI2CDevice );
   } else {
      result = true;
   }
   return result;
}

bool CPBBoneBlackI2C::closeDevice()
{
   debug( "closeDevice" );

   bool result = false;

   if( 0 > mI2CHandle && 0 > close( mI2CHandle ) ) {
      debug( "error close device" );
   } else {
      result = true;
   }

   return result;
}

bool CPBBoneBlackI2C::initSlave( const unsigned char & addr )
{
   debug( "initSlave" );

   bool result = false;
   if( 0 < mI2CHandle ) {
      const int ioResult = ioctl( mI2CHandle, I2C_SLAVE, addr );
      if( 0 > ioResult ) {
         debug( "initSlave error intitalizing"  );
      } else {
         result = true;
      }
   } else {
      debug( "initSlave device is not open"  );
      result = false;
   }
   return result;
}

bool CPBBoneBlackI2C::readByteData( const unsigned char & devRegister, uint8_t & data )
{
   bool result = false;

   __s32 byteData = i2c_smbus_read_byte_data( mI2CHandle, devRegister );
   if( 0 > byteData ) {
      debug( "readByteData can't read data" );
      std::cout << byteData << strerror(byteData) << endl;
   } else {
      data = byteData;
      std::cout << "readByteData data " << std::dec << byteData << endl;
      result = true;
   }

   return result;
}

bool CPBBoneBlackI2C::writeByteData(const uint8_t & command, const uint8_t & value )
{
   bool result = false;

   if ( 0 < mI2CHandle ) {
      int32_t error = i2c_smbus_write_byte_data( mI2CHandle, command, value );
      if( 0 == error ) {
         result = true;
      } else {
         debug( "writeByteData can't write data" );
         std::cout << errno << strerror(errno) << endl;
      }
   }

   return result;
}
