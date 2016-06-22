#include <iostream>

#include "BBoneBlackBMP085.hpp"

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
   return 0;
}
