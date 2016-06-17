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

CPBBoneBlackI2C::CPBBoneBlackI2C( const std::string & i2cDevice )
   : CPDebugMessage( "CPBBoneBlackI2C" )
   , mI2CDevice( i2cDevice )
{

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

bool CPBBoneBlackI2C::readByteData( const unsigned char & devRegister, unsigned char & data )
{
   bool result = false;

   __s32 byteData = i2c_smbus_read_byte_data( mI2CHandle, devRegister );
   if( 0 > byteData ) {
      debug( "readByteData can't read data" );
      std::cout << byteData << strerror(byteData) << endl;
   } else {
      data = byteData && 0xFF;
      result = true;
   }

   return result;
}

bool CPBBoneBlackI2C::writeByteData( const unsigned char & command, const unsigned char & value )
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

bool CPBBoneBlackI2C::initGyro()
{
   debug( "initGyro" );

   bool result = false;

   // int opResult = ioctl(mI2CHandle, I2C_TENBIT, 0);
   const int ioResult = ioctl( mI2CHandle, I2C_SLAVE, I2C_GYRO_ADDR );
   if( -1 == ioResult ) {
       debug( "error intitalizing i2c device: L3G4200D" );
   } else {
      result = true;
   }

   return result;
}

unsigned int CPBBoneBlackI2C::readTemperature()
{
   debug( "readTemperature" );
   long temperature = INT32_MIN;

   if( 0 < mI2CHandle )
   {
      // Write 0x2E into Register 0xF4
      // This requests a temperature reading
      const bool result = writeByteData( 0xF4,0x2E );

      if( result  ) {
         usleep(500);
         // Read the two byte result from address 0xF6
         __s32 msb = i2c_smbus_read_byte_data( mI2CHandle,0xF6 );
         __s32 lsb = i2c_smbus_read_byte_data( mI2CHandle,0xF7 );
         if( ( -1 != msb ) && ( -1 != lsb ) ) {
            temperature = ( msb << 8 ) + lsb;
         } else {
            debug( "CPBBoneBlackI2C::readTemperature can't read 0xF6 0xF7" );
            std::cout << msb << lsb << std::endl;
         }
      } else {
         debug( "CPBBoneBlackI2C::readTemperature can't write 0x2E into Register 0xF4" );
      }
   }
   return temperature;
}

