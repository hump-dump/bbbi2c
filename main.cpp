#include <iostream>

#include "CPBBoneBlackI2C.hpp"

using namespace std;

int main()
{
   cout << "Hello!" << endl;

   CPBBoneBlackI2C i2cDev;

   cout << ( i2cDev.openDevice() ? "true" : "false" ) << std::endl;
   cout << ( i2cDev.closeDevice() ? "true" : "false" ) << std::endl;
   return 0;
}
