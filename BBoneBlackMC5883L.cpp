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
         if( mI2CDevice.writeByteData( REG_MODE, mCurrentSpeed | opMode ) ) {
            mCurrentOpMode = opMode;
         } else {
            debug( "error while configuring Operation Mode" );
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

bool BBoneBlackMC5883L::setI2CSpeed(const eI2CSpeed & speed )
{
   bool result = true;

   if( mI2CDevice.openDevice() ) {
      if( mI2CDevice.initSlave( I2C_MC5883L_ADDR ) ) {
         if( mI2CDevice.writeByteData( REG_MODE, speed | mCurrentOpMode ) ) {
            mCurrentSpeed = speed;
         } else {
            debug( "error while configuring i2c speed" );
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

bool BBoneBlackMC5883L::setMeasurementMode( const BBoneBlackMC5883L::eMeasurementMode & measurementMode )
{
   bool result = true;

   if( mI2CDevice.openDevice() ) {
      if( mI2CDevice.initSlave( I2C_MC5883L_ADDR ) ) {
         if( mI2CDevice.writeByteData( REG_CONF_A, mCurrentMeasurementSamples | mCurrentDataOutputRate | measurementMode ) ) {
            mCurrentMeasurementMode = measurementMode;
         } else {
            debug( "error while configuring Measurement Mode" );
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

bool BBoneBlackMC5883L::setDataOutputRate( const BBoneBlackMC5883L::eDataOutputRate & dataOutputRate )
{
   bool result = true;

   if( mI2CDevice.openDevice() ) {
      if( mI2CDevice.initSlave( I2C_MC5883L_ADDR ) ) {
         if( mI2CDevice.writeByteData( REG_CONF_A, mCurrentMeasurementSamples | dataOutputRate | mCurrentMeasurementMode ) ) {
            mCurrentDataOutputRate = dataOutputRate;
         } else {
            debug( "error while configuring Data Output Rate" );
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

bool BBoneBlackMC5883L::setMeasurementSamples( const BBoneBlackMC5883L::eMeasurementSamples & measurementSamples )
{
   bool result = true;

   if( mI2CDevice.openDevice() ) {
      if( mI2CDevice.initSlave( I2C_MC5883L_ADDR ) ) {
         if( mI2CDevice.writeByteData( REG_CONF_A, measurementSamples | mCurrentDataOutputRate | mCurrentMeasurementMode ) ) {
            mCurrentMeasurementSamples = measurementSamples;
         } else {
            debug( "error while configuring Measurement Samples" );
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
