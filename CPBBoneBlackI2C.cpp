#include "CPBBoneBlackI2C.hpp"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "iostream"

using namespace std;

CPBBoneBlackI2C::CPBBoneBlackI2C()
{

}

bool CPBBoneBlackI2C::openDevice()
{
   bool result = false;
   mI2CHandle = open( "/dev/i2c-1", O_RDWR );
   if( 0 > mI2CHandle ) {
      cout << "can't open i2c device file" << endl;
   } else {
      result = true;
   }

   return result;
}

bool CPBBoneBlackI2C::closeDevice()
{
   bool result = false;

   if( 0 <= close( mI2CHandle ) )
   {
      result = true;
   }

   return result;
}
