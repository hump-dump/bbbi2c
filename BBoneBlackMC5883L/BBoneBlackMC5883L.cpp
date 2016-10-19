#include "BBoneBlackMC5883L.hpp"

#include "../BBoneBlackI2C/CPBBoneBlackI2C.hpp"

BBoneBlackMC5883L::BBoneBlackMC5883L()
{
}

bool BBoneBlackMC5883L::setGain( const eGainValue & gainValue )
{
   bool result = true;

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {
      if( CPBBoneBlackI2C::getInstance()->initSlave( I2C_MC5883L_ADDR ) ) {
         if( CPBBoneBlackI2C::getInstance()->writeByteData( REG_CONF_B, gainValue ) ) {
            mCurrentGain = gainValue;
         } else {
            cout << "error while configuring gain" << endl;
            result = false;
         }
      }else {
         cout << "can't initialize i2c device" << endl;
         result = false;
      }
   } else {
      cout << "can't open device" << endl;
      result = false;
   }
   return result;
}

bool BBoneBlackMC5883L::setOperationMode( const BBoneBlackMC5883L::eOperatingMode & opMode )
{
   bool result = true;

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {
      if( CPBBoneBlackI2C::getInstance()->initSlave( I2C_MC5883L_ADDR ) ) {
         if( CPBBoneBlackI2C::getInstance()->writeByteData( REG_MODE, mCurrentSpeed | opMode ) ) {
            mCurrentOpMode = opMode;
         } else {
            cout << "error while configuring Operation Mode" << endl;
            result = false;
         }
      }else {
         cout << "can't initialize i2c device" << endl;
         result = false;
      }
   } else {
      cout << "can't open device" << endl;
      result = false;
   }
   return result;
}

bool BBoneBlackMC5883L::setI2CSpeed(const eI2CSpeed & speed )
{
   bool result = true;

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {
      if( CPBBoneBlackI2C::getInstance()->initSlave( I2C_MC5883L_ADDR ) ) {
         if( CPBBoneBlackI2C::getInstance()->writeByteData( REG_MODE, speed | mCurrentOpMode ) ) {
            mCurrentSpeed = speed;
         } else {
            cout << "error while configuring i2c speed" << endl;
            result = false;
         }
      }else {
         cout << "can't initialize i2c device" << endl;
         result = false;
      }
   } else {
      cout << "can't open device" << endl;
      result = false;
   }
   return result;
}

bool BBoneBlackMC5883L::setMeasurementMode( const BBoneBlackMC5883L::eMeasurementMode & measurementMode )
{
   bool result = true;

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {
      if( CPBBoneBlackI2C::getInstance()->initSlave( I2C_MC5883L_ADDR ) ) {
         if( CPBBoneBlackI2C::getInstance()->writeByteData( REG_CONF_A, mCurrentMeasurementSamples | mCurrentDataOutputRate | measurementMode ) ) {
            mCurrentMeasurementMode = measurementMode;
         } else {
            cout << "error while configuring Measurement Mode" << endl;
            result = false;
         }
      }else {
         cout << "can't initialize i2c device" << endl;
         result = false;
      }
   } else {
      cout << "can't open device" << endl;
      result = false;
   }
   return result;
}

bool BBoneBlackMC5883L::setDataOutputRate( const BBoneBlackMC5883L::eDataOutputRate & dataOutputRate )
{
   bool result = true;

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {
      if( CPBBoneBlackI2C::getInstance()->initSlave( I2C_MC5883L_ADDR ) ) {
         if( CPBBoneBlackI2C::getInstance()->writeByteData( REG_CONF_A, mCurrentMeasurementSamples | dataOutputRate | mCurrentMeasurementMode ) ) {
            mCurrentDataOutputRate = dataOutputRate;
         } else {
            cout << "error while configuring Data Output Rate" << endl;
            result = false;
         }
      }else {
         cout << "can't initialize i2c device" << endl;
         result = false;
      }
   } else {
      cout << "can't open device" << endl;
      result = false;
   }
   return result;
}

bool BBoneBlackMC5883L::setMeasurementSamples( const BBoneBlackMC5883L::eMeasurementSamples & measurementSamples )
{
   bool result = true;

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {
      if( CPBBoneBlackI2C::getInstance()->initSlave( I2C_MC5883L_ADDR ) ) {
         if( CPBBoneBlackI2C::getInstance()->writeByteData( REG_CONF_A, measurementSamples | mCurrentDataOutputRate | mCurrentMeasurementMode ) ) {
            mCurrentMeasurementSamples = measurementSamples;
         } else {
            cout << "error while configuring Measurement Samples" << endl;
            result = false;
         }
      }else {
         cout << "can't initialize i2c device" << endl;
         result = false;
      }
   } else {
      cout << "can't open device" << endl;
      result = false;
   }
   return result;
}
