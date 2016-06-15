#include <iostream>

#include "CPDebugMessage.hpp"
#include "CPBBoneBlackI2C.hpp"

using namespace std;

int main()
{
   cout << "Hello!" << endl;

   CPBBoneBlackI2C i2cDev;
   cout << ( i2cDev.openDevice() ? "true" : "false" ) << endl;
   cout << ( i2cDev.initGyro() ? "true" : "false" ) << endl;
   cout << ( i2cDev.initBMP085() ? "true" : "false" ) << endl;
   cout << "temp " << i2cDev.readTemperature() << endl;
   cout << ( i2cDev.closeDevice() ? "true" : "false" ) << endl;
   return 0;
}
