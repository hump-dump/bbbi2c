#include <iostream>

#include "BBoneBlackBMP085.hpp"
#include "BBoneBlackMC5883L.hpp"

using namespace std;

int main()
{
   cout << "Hello!" << endl;

   BBoneBlackBMP085 mBMP085;
   mBMP085.init();
   float temperature = 0;
   mBMP085.getTemperature( temperature );
   cout << "current temperature 'C: " << temperature << endl;
   long pressure = 0;
   mBMP085.getPressure( pressure );
   cout << "current pressure: " << pressure << endl;

   BBoneBlackMC5883L mMC5883L;

   cout << "mMC5883L.setGain " << ( mMC5883L.setGain( BBoneBlackMC5883L::RANGE_1_3GA ) ? "true" : "false" ) << endl;

   return 0;
}
