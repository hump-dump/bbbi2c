#ifndef BBONEBLACKMC5883L_HPP
#define BBONEBLACKMC5883L_HPP

#include "CPDebugMessage.hpp"
#include "CPBBoneBlackI2C.hpp"

#define I2C_MC5883L_ADDR 0x1E  // 3 Axis Magnetometer	Honeywell MC5883L

class BBoneBlackMC5883L
   : public CPDebugMessage
{
public:
   enum eRegisters {
      REG_CONF_A = 0x00,  // Read/Write
      REG_CONF_B = 0x01,  // Read/Write
      REG_MODE   = 0x02,  // Read/Write
      REG_DATA_X_MSB   = 0x03,  // Read
      REG_DATA_X_LSB   = 0x04,  // Read
      REG_DATA_Z_MSB   = 0x05,  // Read
      REG_DATA_Z_LSB   = 0x06,  // Read
      REG_DATA_Y_MSB   = 0x07,  // Read
      REG_DATA_Y_LSB   = 0x08,  // Read
      REG_STATUS = 0x09,  // Read
      REG_ID_A   = 0x0A,  // Read
      REG_ID_B   = 0x0B,  // Read
      REG_ID_C   = 0x0C  // Read
   };

   enum eGainValue {
      RANGE_0_88GA = 0b00000000,
      RANGE_1_3GA  = 0b00100000,
      RANGE_1_9GA  = 0b01000000,
      RANGE_2_5GA  = 0b01100000,
      RANGE_4_0GA  = 0b10000000,
      RANGE_4_7GA  = 0b10100000,
      RANGE_5_6GA  = 0b11000000,
      RANGE_8_1GA  = 0b11100000
   };
   enum eOperationMode {
      OPMODE_CONTINUOUS = 0b00,
      OPMODE_SINGLE     = 0b01,
      OPMODE_IDLE       = 0b10,
      OPMODE_IDLE0      = 0b11
   };

   BBoneBlackMC5883L();
   void setGain(  );
private:
   CPBBoneBlackI2C mI2CDevice;
};

#endif // BBONEBLACKMC5883L_HPP
