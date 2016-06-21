#include "BBoneBlackBMP085.hpp"

#include <unistd.h>
#include <iostream>

BBoneBlackBMP085::BBoneBlackBMP085()
   : CPDebugMessage( "BBoneBlackBMP085" )
   , mI2CDevice( "/dev/i2c-2" )
{

}

bool BBoneBlackBMP085::readCalibrationData()
{
   bool result = true;

   if( mI2CDevice.openDevice() ) {
      if( mI2CDevice.initSlave( I2C_BMP085_ADDR ) ) {
         CPBBoneBlackI2C::uShort regData;
         // AC1: EPROM registers 0xAA, 0xAB
         if( mI2CDevice.readByteData( static_cast<unsigned char>(0xAA), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xAB), regData.bytes[0] ) ) {
            mCalibrationData.AC1 = regData.sValue;
            std::cout << "readCalibrationData AC1 " << mCalibrationData.AC1 << std::endl;
         } else {
            result = false;
         }
         // AC2: EPROM registers 0xAC, 0xAD
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xAC), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xAD), regData.bytes[0] ) ) {
            mCalibrationData.AC2 = regData.sValue;
            std::cout << "readCalibrationData AC2 " << mCalibrationData.AC2 << std::endl;
         } else {
            result = false;
         }
         // AC3: EPROM registers 0xAE, 0xAF
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xAE), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xAF), regData.bytes[0] ) ) {
            mCalibrationData.AC3 = regData.sValue;
            std::cout << "readCalibrationData AC3 " << mCalibrationData.AC3 << std::endl;
         } else {
            result = false;
         }
         // AC4: EPROM registers 0xB0, 0xB1
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xB0), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xB1), regData.bytes[0] ) ) {
            mCalibrationData.AC4 = regData.uValue;
            std::cout << "readCalibrationData AC4 " << mCalibrationData.AC4 << std::endl;
         } else {
            result = false;
         }
         // AC5: EPROM registers 0xB2, 0xB3
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xB2), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xB3), regData.bytes[0] ) ) {
            mCalibrationData.AC5 = regData.uValue;
            std::cout << "readCalibrationData AC5 " << mCalibrationData.AC5 << std::endl;
         } else {
            result = false;
         }
         // AC6: EPROM registers 0xB4, 0xB5
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xB4), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xB5), regData.bytes[0] ) ) {
            mCalibrationData.AC6 = regData.uValue;
            std::cout << "readCalibrationData AC6 " << mCalibrationData.AC6 << std::endl;
         } else {
            result = false;
         }
         // B1: EPROM registers 0xB6, 0xB7
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xB6), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xB7), regData.bytes[0] ) ) {
            mCalibrationData.B1 = regData.sValue;
            std::cout << "readCalibrationData B1 " << mCalibrationData.B1 << std::endl;
         } else {
            result = false;
         }
         // B2: EPROM registers 0xB8, 0xB9
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xB8), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xB9), regData.bytes[0] ) ) {
            mCalibrationData.B2 = regData.sValue;
            std::cout << "readCalibrationData B2 " << mCalibrationData.B2 << std::endl;
         } else {
            result = false;
         }
         // MB: EPROM registers 0xBA, 0xBB
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xBA), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xBB), regData.bytes[0] ) ) {
            mCalibrationData.MB = regData.sValue;
            std::cout << "readCalibrationData MB " << mCalibrationData.MB << std::endl;
         } else {
            result = false;
         }
         // MC: EPROM registers 0xBC, 0xBD
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xBC), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xBD), regData.bytes[0] ) ) {
            mCalibrationData.MC = regData.sValue;
            std::cout << "readCalibrationData MC " << mCalibrationData.MC << std::endl;
         } else {
            result = false;
         }
         // MD: EPROM registers 0xBE, 0xBF
         if( result && mI2CDevice.readByteData( static_cast<unsigned char>(0xBE), regData.bytes[1] )
             && mI2CDevice.readByteData( static_cast<unsigned char>(0xBF), regData.bytes[0] ) ) {
            mCalibrationData.MD = regData.sValue;
            std::cout << "readCalibrationData MD " << mCalibrationData.MD << std::endl;
         } else {
            result = false;
         }
      } else {
         debug( "can't initialze BMP085" );
         result = false;
      }
      mI2CDevice.closeDevice();
   } else {
      debug( "can't open device" );
      result = false;
   }

   return result;
}

bool  BBoneBlackBMP085::readUncompensatedTemperature( long & UncompensatedTemperature )
{
   bool result = true;

   if( mI2CDevice.openDevice() ) {
      if( mI2CDevice.initSlave( I2C_BMP085_ADDR ) ) {
         // Write 0x2E into Register 0xF4
         // This requests a temperature reading
         if( mI2CDevice.writeByteData( 0xF4,0x2E ) ) {
            debug("Waiting...");
            usleep( 10000 );
         } else {
            result = false;
         }
         CPBBoneBlackI2C::uShort regData;

         if( result && mI2CDevice.readByteData( 0xF6, regData.bytes[1] )
             && mI2CDevice.readByteData( 0xF7, regData.bytes[0] ) ) {
            std::cout << "readUncompensatedTemperature sValue " << regData.sValue << std::endl;
            UncompensatedTemperature = regData.sValue;
         } else {
            result = false;
         }
         mI2CDevice.closeDevice();
      } else {
         debug( "can't open device" );
      }
   }

   return result;
}

bool BBoneBlackBMP085::getTemperature( float & temperature )
{
   bool result = false;
   long UT = 0;
   if( readCalibrationData() && readUncompensatedTemperature( UT ) ) {
      long X1 =( UT - mCalibrationData.AC6 ) * mCalibrationData.AC5 / ( static_cast<long>(0x01) << 15 );
      long X2 = mCalibrationData.MC * ( static_cast<long>(0x01) << 11 ) /( X1 + mCalibrationData.MD );
      temperature = ( X1 + X2 +8 ) / ( static_cast<long>(0x01) << 4 );
      temperature /= 10;
   }
   return result;
}
