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

// -----------------------------------------
// Workaround for cross compilation MINI2440

/* Returns the number of read bytes */
static inline __s32 i2c_smbus_read_block_data(int file, __u8 command,
                                              __u8 *values)
{
   union i2c_smbus_data data;
   int i;
   if (i2c_smbus_access(file,I2C_SMBUS_READ,command,
                        I2C_SMBUS_BLOCK_DATA,&data))
      return -1;
   else {
      for (i = 1; i <= data.block[0]; i++)
         values[i-1] = data.block[i];
      return data.block[0];
   }
}

static inline __s32 i2c_smbus_write_block_data(int file, __u8 command,
                                               __u8 length, const __u8 *values)
{
   union i2c_smbus_data data;
   int i;
   if (length > 32)
      length = 32;
   for (i = 1; i <= length; i++)
      data.block[i] = values[i-1];
   data.block[0] = length;
   return i2c_smbus_access(file,I2C_SMBUS_WRITE,command,
                           I2C_SMBUS_BLOCK_DATA, &data);
}

// -----------------------------------------

#endif // CPBBONEBLACKI2C_HPP
