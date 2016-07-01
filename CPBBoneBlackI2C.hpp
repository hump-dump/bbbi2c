#ifndef CPBBONEBLACKI2C_HPP
#define CPBBONEBLACKI2C_HPP

#include <string>
#include <cstdint>

#include "CPDebugMessage.hpp"

class CPBBoneBlackI2C
   : public CPDebugMessage
{
public:
   enum eResult {
      RESULT_OK,
      RESULT_ERROR,
      RESULT_NOT_INITIALIZED,
      RESULT_NOT_OPENED
   };

   static CPBBoneBlackI2C* getInstance()
   {
      static CPBBoneBlackI2C i2c;
      return &i2c;
   }

   eResult setDeviceName( const std::string & deviceName );
   bool openDevice();
   bool closeDevice();
   bool initSlave( const unsigned char & addr );
   bool readByteData( const unsigned char & devRegister, uint8_t & data );
   bool writeByteData( const uint8_t & command, const uint8_t & value );
protected:
   CPBBoneBlackI2C();
   CPBBoneBlackI2C( const CPBBoneBlackI2C & );
   CPBBoneBlackI2C & operator = ( const CPBBoneBlackI2C & );
private:
   const std::string mI2CDevice;
   int mI2CHandle = -1;
};

#endif // CPBBONEBLACKI2C_HPP
