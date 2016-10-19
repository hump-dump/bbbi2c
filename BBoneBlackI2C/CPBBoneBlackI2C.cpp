#include "CPBBoneBlackI2C.hpp"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <iostream>
// #include "CPDebugMessage.hpp"

using namespace std;

CPBBoneBlackI2C::eResult CPBBoneBlackI2C::setDeviceName( const std::string & deviceName )
{
   CPBBoneBlackI2C::eResult result = RESULT_OK;

   if( -1 == mI2CHandle ) {
      mI2CDevice = deviceName;
   } else {
      result = CPBBoneBlackI2C::RESULT_ERROR;
   }

   return result;
}

CPBBoneBlackI2C::eResult CPBBoneBlackI2C::openDevice()
{
   std::cout << "openDevice " + mI2CDevice << endl;

   CPBBoneBlackI2C::eResult result = CPBBoneBlackI2C::RESULT_OK;

   if( ! mI2CDevice.empty() ) {
      if( -1 == mI2CHandle ) {
         mI2CHandle = open( mI2CDevice.c_str(), O_RDWR );
         if( -1 == mI2CHandle ) {
            std::cout << "can't open i2c device " + mI2CDevice << endl;
            result = CPBBoneBlackI2C::RESULT_ERROR;
         }
      }
   } else {
      result = CPBBoneBlackI2C::RESULT_NOT_INITIALIZED;
   }

   return result;
}

bool CPBBoneBlackI2C::closeDevice()
{
   std::cout << "closeDevice" << endl;

   bool result = false;

   if( -1 != mI2CHandle && -1 == close( mI2CHandle ) ) {
      std::cout << "error close device" << endl;
   } else {
      mI2CHandle = -1;
      result = true;
   }

   return result;
}

bool CPBBoneBlackI2C::initSlave( const unsigned char & addr )
{
   std::cout << "initSlave" << endl;

   bool result = false;
   if( -1 != mI2CHandle ) {
      const int ioResult = ioctl( mI2CHandle, I2C_SLAVE, addr );
      if( 0 > ioResult ) {
         std::cout << "initSlave error intitalizing" << endl;
      } else {
         result = true;
      }
   } else {
      std::cout << "initSlave device is not open" << endl;
      result = false;
   }
   return result;
}

bool CPBBoneBlackI2C::readByteData( const unsigned char & devRegister, uint8_t & data )
{
   bool result = false;

   if ( -1 != mI2CHandle ) {
      __s32 byteData = i2c_smbus_read_byte_data( mI2CHandle, devRegister );
      if( 0 > byteData ) {
         std::cout << "readByteData can't read data" << endl;
         std::cout << byteData << strerror(byteData) << endl;
      } else {
         data = byteData;
         std::cout << "readByteData data " << std::dec << byteData << endl;
         result = true;
      }
   }

   return result;
}

bool CPBBoneBlackI2C::writeByteData(const uint8_t & command, const uint8_t & value )
{
   bool result = false;

   if ( -1 != mI2CHandle ) {
      int32_t error = i2c_smbus_write_byte_data( mI2CHandle, command, value );
      if( 0 == error ) {
         result = true;
      } else {
         std::cout << "writeByteData can't write data" << endl;
         std::cout << errno << strerror(errno) << endl;
      }
   }

   return result;
}

std::string CPBBoneBlackI2C::toString( const CPBBoneBlackI2C::eResult & result )
{
   std::string value;

   switch ( result ) {
   default: value = "Undefined"; break;
   }

   return value;
}
