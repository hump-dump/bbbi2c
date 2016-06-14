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
{

}

bool CPBBoneBlackI2C::openDevice()
{
   CPDebugMessage::debug( "CPBBoneBlackI2C::openDevice" );

   bool result = false;

   mI2CHandle = open( "/dev/i2c-1", O_RDWR );
   if( 0 > mI2CHandle ) {
      CPDebugMessage::debug( "can't open i2c device file /dev/i2c-1" );
   } else {
      result = true;
   }
   return result;
}

bool CPBBoneBlackI2C::closeDevice()
{
   CPDebugMessage::debug( "CPBBoneBlackI2C::closeDevice" );

   bool result = false;

   if( 0 > mI2CHandle && 0 > close( mI2CHandle ) ) {
      CPDebugMessage::debug( "error close device" );
   } else {
      result = true;
   }

   return result;
}

bool CPBBoneBlackI2C::initGyro()
{
   CPDebugMessage::debug( "CPBBoneBlackI2C::initGyro" );

   bool result = false;

   // int opResult = ioctl(mI2CHandle, I2C_TENBIT, 0);
   const int ioResult = ioctl( mI2CHandle, I2C_SLAVE, I2C_GYRO_ADDR );
   if( 0 > ioResult ) {
       CPDebugMessage::debug( "error intitalizing i2c device: L3G4200D" );
   } else {
      result = true;
   }

   return result;
}

bool CPBBoneBlackI2C::initBMP085()
{
   CPDebugMessage::debug( "CPBBoneBlackI2C::initBMP085" );

   bool result = false;

   const int ioResult = ioctl( mI2CHandle, I2C_SLAVE, I2C_GYRO_ADDR );
   if( 0 > ioResult ) {
       CPDebugMessage::debug( "error intitalizing i2c device: BMP085" );
   } else {
      result = true;
   }

   return result;
}

int32_t CPBBoneBlackI2C::readTemperature()
{
   CPDebugMessage::debug( "CPBBoneBlackI2C::readTemperature" );
   int32_t temp = INT32_MIN;

   if( 0 < mI2CHandle )
   {
      // Write 0x2E into Register 0xF4
      // This requests a temperature reading
      int32_t result = i2c_smbus_write_byte_data( mI2CHandle,0xF4,0x2E );

      if( 0 > result  ) {
         usleep(5000);
         // Read the two byte result from address 0xF6
         int32_t result = i2c_smbus_read_word_data( mI2CHandle,0xF6 );
         if( 0 > result ) {
            temp = ((result<<8) & 0xFF00) | ((result>>8) & 0xFF);
         } else {

            CPDebugMessage::debug( "CPBBoneBlackI2C::readTemperature can't read 0xF6" );
         }
      } else {
         CPDebugMessage::debug( "CPBBoneBlackI2C::readTemperature can't write 0x2E into Register 0xF4" );
      }
   }
   return temp;
}
