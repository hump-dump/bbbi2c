#ifndef CPBBONEBLACKI2C_HPP
#define CPBBONEBLACKI2C_HPP

#include <string>
#include <cstdint>

class CPBBoneBlackI2C
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

   CPBBoneBlackI2C::eResult setDeviceName( const std::string & deviceName );
   CPBBoneBlackI2C::eResult openDevice();
   bool closeDevice();
   bool initSlave( const unsigned char & addr );
   bool readByteData( const unsigned char & devRegister, uint8_t & data );
   bool writeByteData( const uint8_t & command, const uint8_t & value );
   static std::string toString( const CPBBoneBlackI2C::eResult & result );
   inline bool isOpened() const;
private:
   CPBBoneBlackI2C() {}
   CPBBoneBlackI2C( const CPBBoneBlackI2C & );
   CPBBoneBlackI2C & operator = ( const CPBBoneBlackI2C & );

   std::string mI2CDevice;
   int mI2CHandle = -1;
};

inline bool CPBBoneBlackI2C::isOpened() const
{
   return ( -1 != mI2CHandle );
}

#endif // CPBBONEBLACKI2C_HPP
