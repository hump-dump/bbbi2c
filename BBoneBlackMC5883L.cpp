#include "BBoneBlackMC5883L.hpp"

BBoneBlackMC5883L::BBoneBlackMC5883L()
   : CPDebugMessage( "MC5883L" )
   , mI2CDevice( "/dev/i2c-2" )
{
   mI2CDevice.setParent( *this );
}

void BBoneBlackMC5883L::setGain(  )
{

}
