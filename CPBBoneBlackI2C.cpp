#include "CPBBoneBlackI2C.hpp"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <iostream>
#include "CPDebugMessage.hpp"

using namespace std;

CPBBoneBlackI2C::CPBBoneBlackI2C()
   : CPDebugMessage( "CPBBoneBlackI2C" )
{

}

bool CPBBoneBlackI2C::openDevice()
{
   debug( "openDevice" );

   bool result = false;

   mI2CHandle = open( "/dev/i2c-1", O_RDWR );
   if( 0 > mI2CHandle ) {
      debug( "can't open i2c device file /dev/i2c-1" );
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

bool CPBBoneBlackI2C::writeByteData( const unsigned char & command, const unsigned char & value )
{
   bool result = false;

   if ( 0 < mI2CHandle ) {
      int32_t error = i2c_smbus_write_byte_data( mI2CHandle, command, value );
      if( 0 == error ) {
         result = true;
      } else {
         debug( "writeByteData can't write data" );
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
   if( 0 > ioResult ) {
       debug( "error intitalizing i2c device: L3G4200D" );
   } else {
      result = true;
   }

   return result;
}

bool CPBBoneBlackI2C::initBMP085()
{
   debug( "initBMP085" );

   bool result = false;

   const int ioResult = ioctl( mI2CHandle, I2C_SLAVE, I2C_GYRO_ADDR );
   if( 0 > ioResult ) {
       CPDebugMessage::debug( "error intitalizing i2c device: BMP085" );
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
      const bool result = writeByteData( mI2CHandle,0xF4,0x2E );

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

void CPBBoneBlackI2C::readCalibrationData()
{
   debug( "readCalibrationData" );
}
