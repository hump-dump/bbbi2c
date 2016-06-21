#include <iostream>

#include "BBoneBlackBMP085.hpp"

using namespace std;

int main()
{
   cout << "Hello!" << endl;

   BBoneBlackBMP085 mBMP085;
   mBMP085.readCalibrationData();
   float temperature = 0;
   mBMP085.getTemperature( temperature );

   return 0;
}
