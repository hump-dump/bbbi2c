#ifndef CPBBONEBLACKI2C_HPP
#define CPBBONEBLACKI2C_HPP

#include <string>
#include <cstdint>

#include "CPDebugMessage.hpp"

#define I2C_GYRO_ADDR   0x69 // 3 Axis Gyro	ST Microelectronics L3G4200D

class CPBBoneBlackI2C
   : public CPDebugMessage
{
public:
   CPBBoneBlackI2C( const std::string & i2cDevice );

   bool openDevice();
   bool closeDevice();
   bool initSlave( const unsigned char & addr );
   bool readByteData(const unsigned char & devRegister, uint8_t & data );
   bool writeByteData( const uint8_t & command, const uint8_t & value );
   bool initGyro();
   unsigned int readTemperature();
protected:
   CPBBoneBlackI2C();
   CPBBoneBlackI2C( const CPBBoneBlackI2C & );
   CPBBoneBlackI2C & operator = ( const CPBBoneBlackI2C & );
private:
   const std::string mI2CDevice;
   int mI2CHandle = -1;
};

#endif // CPBBONEBLACKI2C_HPP
