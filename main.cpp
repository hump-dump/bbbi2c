#include <iostream>

#include "CPDebugMessage.hpp"
#include "CPBBoneBlackI2C.hpp"

using namespace std;

int main()
{
   cout << "Hello!" << endl;

   CPBBoneBlackI2C i2cDev;
   CPDebugMessage::debug( i2cDev.openDevice() ? "true" : "false" );
   CPDebugMessage::debug( i2cDev.initGyro() ? "true" : "false" );
   CPDebugMessage::debug( i2cDev.initBMP085() ? "true" : "false" );
   cout << "temp" << i2cDev.readTemperature() << endl;
   CPDebugMessage::debug( i2cDev.closeDevice() ? "true" : "false" );
   return 0;
}
