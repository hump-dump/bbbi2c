#ifndef CPBBONEBLACKI2C_HPP
#define CPBBONEBLACKI2C_HPP

#include <string>
#include <cstdint>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

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

static inline __s32 i2c_smbus_access(int file, char read_write, __u8 command,
                                     int size, union i2c_smbus_data *data)
{
   struct i2c_smbus_ioctl_data args;

   args.read_write = read_write;
   args.command = command;
   args.size = size;
   args.data = data;
   return ioctl(file,I2C_SMBUS,&args);
}

static inline __s32 i2c_smbus_read_byte_data(int file, __u8 command)
{
   union i2c_smbus_data data;
   if (i2c_smbus_access(file,I2C_SMBUS_READ,command,
                        I2C_SMBUS_BYTE_DATA,&data))
      return -1;
   else
      return 0x0FF & data.byte;
}

static inline __s32 i2c_smbus_write_byte_data(int file, __u8 command,
                                              __u8 value)
{
   union i2c_smbus_data data;
   data.byte = value;
   return i2c_smbus_access(file,I2C_SMBUS_WRITE,command,
                           I2C_SMBUS_BYTE_DATA, &data);
}

// -----------------------------------------

#endif // CPBBONEBLACKI2C_HPP
