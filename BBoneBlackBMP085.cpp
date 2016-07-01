#include "BBoneBlackBMP085.hpp"

#include <unistd.h>
#include <iostream>

#include "CPBBoneBlackI2C.hpp"

BBoneBlackBMP085::BBoneBlackBMP085()
   : CPDebugMessage( "BMP085" )
{
}

void BBoneBlackBMP085::init()
{
   readCalibrationData();
}

void BBoneBlackBMP085::readCalibrationData()
{
   bool result = true;

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {
      if( CPBBoneBlackI2C::getInstance()->initSlave( I2C_BMP085_ADDR ) ) {
         uint8_t msb = 0;
         uint8_t lsb = 0;
         // AC1: EPROM registers 0xAA, 0xAB
         if( CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xAA), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xAB), lsb ) ) {
            mCalibrationData.AC1 = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData AC1 " << mCalibrationData.AC1 << std::endl;
         } else {
            result = false;
         }
         // AC2: EPROM registers 0xAC, 0xAD
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xAC), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xAD), lsb ) ) {
            mCalibrationData.AC2 = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData AC2 " << mCalibrationData.AC2 << std::endl;
         } else {
            result = false;
         }
         // AC3: EPROM registers 0xAE, 0xAF
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xAE), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xAF), lsb ) ) {
            mCalibrationData.AC3 = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData AC3 " << mCalibrationData.AC3 << std::endl;
         } else {
            result = false;
         }
         // AC4: EPROM registers 0xB0, 0xB1
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB0), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB1), lsb ) ) {
            mCalibrationData.AC4 = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData AC4 " << mCalibrationData.AC4 << std::endl;
         } else {
            result = false;
         }
         // AC5: EPROM registers 0xB2, 0xB3
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB2), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB3), lsb ) ) {
            mCalibrationData.AC5 = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData AC5 " << mCalibrationData.AC5 << std::endl;
         } else {
            result = false;
         }
         // AC6: EPROM registers 0xB4, 0xB5
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB4), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB5), lsb ) ) {
            mCalibrationData.AC6 = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData AC6 " << mCalibrationData.AC6 << std::endl;
         } else {
            result = false;
         }
         // B1: EPROM registers 0xB6, 0xB7
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB6), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB7), lsb ) ) {
            mCalibrationData.B1 = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData B1 " << mCalibrationData.B1 << std::endl;
         } else {
            result = false;
         }
         // B2: EPROM registers 0xB8, 0xB9
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB8), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xB9), lsb ) ) {
            mCalibrationData.B2 = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData B2 " << mCalibrationData.B2 << std::endl;
         } else {
            result = false;
         }
         // MB: EPROM registers 0xBA, 0xBB
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xBA), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xBB), lsb ) ) {
            mCalibrationData.MB = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData MB " << mCalibrationData.MB << std::endl;
         } else {
            result = false;
         }
         // MC: EPROM registers 0xBC, 0xBD
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xBC), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xBD), lsb ) ) {
            mCalibrationData.MC = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData MC " << mCalibrationData.MC << std::endl;
         } else {
            result = false;
         }
         // MD: EPROM registers 0xBE, 0xBF
         if( result && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xBE), msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( static_cast<unsigned char>(0xBF), lsb ) ) {
            mCalibrationData.MD = ( msb << 8 ) + lsb;
            std::cout << "readCalibrationData MD " << mCalibrationData.MD << std::endl;
         } else {
            result = false;
         }
      } else {
         debug( "can't initialze BMP085" );
         result = false;
      }
      CPBBoneBlackI2C::getInstance()->closeDevice();
   } else {
      debug( "can't open device" );
      result = false;
   }
   mCalibrationData.isActual = result;
}

bool BBoneBlackBMP085::readUncompensatedTemperature( long & UncompensatedTemperature )
{
   bool result = true;

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {
      if( CPBBoneBlackI2C::getInstance()->initSlave( I2C_BMP085_ADDR ) ) {
         // Write 0x2E into Register 0xF4
         // This requests a temperature reading
         if( CPBBoneBlackI2C::getInstance()->writeByteData( 0xF4,0x2E ) ) {
            usleep( 5000 );
         } else {
            result = false;
         }
         uint8_t msb = 0;
         uint8_t lsb = 0;
         if( result
             && CPBBoneBlackI2C::getInstance()->readByteData( 0xF6, msb )
             && CPBBoneBlackI2C::getInstance()->readByteData( 0xF7, lsb ) ) {
            UncompensatedTemperature = ( msb << 8 ) + lsb;
            std::cout << "readUncompensatedTemperature sValue " << UncompensatedTemperature << std::endl;
         } else {
            result = false;
         }
         CPBBoneBlackI2C::getInstance()->closeDevice();
      } else {
         debug( "can't initialize i2c device" );
         result = false;
      }
   } else {
      debug( "can't open device" );
      result = false;
   }

   return result;
}

bool BBoneBlackBMP085::getTemperature( float & temperature )
{
   bool result = true;

   long UT = 0;
   if( mCalibrationData.isActual && readUncompensatedTemperature( UT ) ) {
      long X1 =( UT - mCalibrationData.AC6 ) * mCalibrationData.AC5 / ( static_cast<long>(0x01) << 15 );
      long X2 = mCalibrationData.MC * ( static_cast<long>(0x01) << 11 ) /( X1 + mCalibrationData.MD );
      temperature = ( X1 + X2 +8 ) / ( static_cast<long>(0x01) << 4 );
      temperature /= 10;
   } else {
      result = false;
   }

   return result;
}

bool BBoneBlackBMP085::readUncompensatedPressure( long & UncompensatedPressure )
{
   bool result = true;

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {
      if( CPBBoneBlackI2C::getInstance()->initSlave( I2C_BMP085_ADDR ) ) {
         // Write 0x2E into Register 0xF4
         // This requests a temperature reading
         if( CPBBoneBlackI2C::getInstance()->writeByteData( 0xF4,0x34 + ( BMP085_OSS << 6 ) ) ) {
            usleep( 5000 );

            uint8_t msb = 0;
            uint8_t lsb = 0;
            uint8_t xlsb = 0;

            if( CPBBoneBlackI2C::getInstance()->readByteData( 0xF6, msb )
                && CPBBoneBlackI2C::getInstance()->readByteData( 0xF7, lsb )
                && CPBBoneBlackI2C::getInstance()->readByteData( 0xF8, xlsb ) ) {
               UncompensatedPressure = ( ( msb << 16 ) + ( lsb << 8 ) + xlsb ) >> ( 8 - BMP085_OSS );
               std::cout << "readUncompensatedTemperature UncompensatedPressure " << UncompensatedPressure << std::endl;
            } else {
               debug( "reading pressure data failed" );
               result = false;
            }

         } else {
            debug( "write data failed" );
            result = false;
         }
         CPBBoneBlackI2C::getInstance()->closeDevice();
      } else {
         debug( "can't initialize i2c device" );
         result = false;
      }
   } else {
      debug( "can't open device" );
      result = false;
   }

   return result;
}

bool BBoneBlackBMP085::getPressure( long & pressure )
{
      bool result = true;

      long UT = 0;
      long UP = 0;
      if ( readUncompensatedTemperature( UT ) && readUncompensatedPressure( UP ) ) {
         long X1 =( UT - mCalibrationData.AC6 ) * mCalibrationData.AC5 / ( static_cast<long>(0x01) << 15 );
         long X2 = mCalibrationData.MC * ( static_cast<long>(0x01) << 11 ) /( X1 + mCalibrationData.MD );
         long B6 = X1 + X2 - 4000;
         X1 = ( mCalibrationData.B2 * ( B6 / ( static_cast<long>(0x01) << 12 ) ) ) / ( static_cast<long>(0x01) << 11 );
         X2 = mCalibrationData.AC2 * B6 / ( static_cast<long>(0x01) << 11 );
         long X3 = X1 + X2;
         long B3 = ( ( ( mCalibrationData.AC1*4 + X3 ) << BMP085_OSS ) + 2 ) / 4;
         X1 = mCalibrationData.AC3 * B6 / ( static_cast<long>(0x01) << 12 );
         X2 = ( mCalibrationData.B1 * ( B6 *B6 / ( static_cast<long>(0x01) << 12 ) ) )/ ( static_cast<long>(0x01) << 16 );
         X3 = ( ( X1 + X2 ) + 2 ) / ( static_cast<long>(0x01) << 2 );
         unsigned long B4 = mCalibrationData.AC4 * static_cast<unsigned long>( X3 + 32768 ) / ( static_cast<long>(0x01) << 15 );
         unsigned long B7 = ( static_cast<unsigned long>( UP - B3) *( 5000 >> BMP085_OSS ) );
         long p = 0;
         if( B7 < 0x80000000 ) {
            p = B7 *2 / B4;
         } else {
            p = B7 / B4 * 2;
         }
         X1 = ( p / ( static_cast<long>(0x01) << 8 ) ) * ( p / ( static_cast<long>(0x01) << 8 ) );
         X1 = ( X1 * 3038 ) / ( static_cast<long>(0x01) << 16 );
         X2 = ( -7357 * p ) / ( static_cast<long>(0x01) << 16 );
         p = p + ( X1 + X2 + 3791 ) / ( static_cast<long>(0x01) << 4 );
         pressure = p;
      } else {
         result = false;
      }

      return result;
}
