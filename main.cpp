#include <iostream>

#include "CPBBoneBlackI2C.hpp"
#include "BBoneBlackBMP085.hpp"
#include "BBoneBlackMC5883L.hpp"

using namespace std;

int main()
{
   cout << "Hello!" << endl;

   CPBBoneBlackI2C::getInstance()->setDeviceName( "/dev/i2c-2" );

   if( CPBBoneBlackI2C::RESULT_OK == CPBBoneBlackI2C::getInstance()->openDevice() ) {


      CPBBoneBlackI2C::getInstance()->closeDevice();
   }

   BBoneBlackBMP085 mBMP085;
   mBMP085.init();
   float temperature = 0;
   mBMP085.getTemperature( temperature );
   cout << "current temperature 'C: " << temperature << endl;
   long pressure = 0;
   mBMP085.getPressure( pressure );
   cout << "current pressure: " << pressure << endl;

   BBoneBlackMC5883L mMC5883L;

   bool result = mMC5883L.setGain( BBoneBlackMC5883L::RANGE_1_9GA );
   cout << "mMC5883L.setGain " << ( result ? "true" : "false" ) << endl;

   result = mMC5883L.setOperationMode( BBoneBlackMC5883L::OPMODE_CONTINUOUS );
   cout << "mMC5883L.setOperationMode " << ( result ? "true" : "false" ) << endl;

   result = mMC5883L.setI2CSpeed( BBoneBlackMC5883L::SPEED_HIGH );
   cout << "mMC5883L.setI2CSpeed " << ( result ? "true" : "false" ) << endl;

   result = mMC5883L.setMeasurementMode( BBoneBlackMC5883L::MM_NORMAL );
   cout << "mMC5883L.setMeasurementMode " << ( result ? "true" : "false" ) << endl;

   result = mMC5883L.setDataOutputRate( BBoneBlackMC5883L::RATE_75 );
   cout << "mMC5883L.setDataOutputRate " << ( result ? "true" : "false" ) << endl;

   result = mMC5883L.setMeasurementSamples( BBoneBlackMC5883L::MA_8 );
   cout << "mMC5883L.setMeasurementSamples " << ( result ? "true" : "false" ) << endl;

   return 0;
}
