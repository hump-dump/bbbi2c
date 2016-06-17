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
   union uShort {
      int16_t sValue = 0x0;
      uint16_t uValue;
      uint8_t bytes[2]; // [ lsb, msb ]
   };

   CPBBoneBlackI2C( const std::string & i2cDevice );

   bool openDevice();
   bool closeDevice();
   bool initSlave( const unsigned char & addr );
   bool readByteData( const unsigned char & devRegister, unsigned char & data );
   bool writeByteData( const unsigned char & command, const unsigned char & value );
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
