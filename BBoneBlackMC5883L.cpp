#include "BBoneBlackMC5883L.hpp"

BBoneBlackMC5883L::BBoneBlackMC5883L()
   : CPDebugMessage( "MC5883L" )
   , mI2CDevice( "/dev/i2c-2" )
{
   mI2CDevice.setParent( *this );
}

bool BBoneBlackMC5883L::setGain( const eGainValue & gainValue )
{
   bool result = true;

   if( mI2CDevice.openDevice() ) {
      if( mI2CDevice.initSlave( I2C_MC5883L_ADDR ) ) {
         if( mI2CDevice.writeByteData( REG_CONF_B, gainValue ) ) {
            mCurrentGain = gainValue;
         } else {
            debug( "error while configuring gain" );
            result = false;
         }
      }else {
         debug( "can't initialize i2c device" );
         result = false;
      }
   } else {
      debug( "can't open device" );
      result = false;
   }
   return result;
}

bool BBoneBlackMC5883L::setOperationMode( const BBoneBlackMC5883L::eOperatingMode & opMode )
{
   bool result = true;

   if( mI2CDevice.openDevice() ) {
      if( mI2CDevice.initSlave( I2C_MC5883L_ADDR ) ) {
         if( mI2CDevice.writeByteData( REG_MODE, opMode ) ) {
            mCurrentOpMode = opMode;
         } else {
            debug( "error while configuring gain" );
            result = false;
         }
      }else {
         debug( "can't initialize i2c device" );
         result = false;
      }
   } else {
      debug( "can't open device" );
      result = false;
   }
   return result;
}
