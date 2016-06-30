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
      RANGE_1_3GA  = 0b00100000,  // Default value
      RANGE_1_9GA  = 0b01000000,
      RANGE_2_5GA  = 0b01100000,
      RANGE_4_0GA  = 0b10000000,
      RANGE_4_7GA  = 0b10100000,
      RANGE_5_6GA  = 0b11000000,
      RANGE_8_1GA  = 0b11100000
   };

   enum eOperatingMode {
      OPMODE_CONTINUOUS = 0b00,
      OPMODE_SINGLE     = 0b01,  // Default value
      OPMODE_IDLE       = 0b10,
      OPMODE_IDLE0      = 0b11
   };

   enum eI2CSpeed {
      SPEED_LOW = 0b00000000,   // DefaultValue
      SPEED_HIGH = 0b11111100
   };

   enum eDataOutputRate {
      RATE_0_75 = 0b000,
      RATE_1_5 = 0b001,
      RATE_3 = 0b010,
      RATE_7_5 = 0b011,
      RATE_15 = 0b100,   // Default value
      RATE_30 = 0b101,
      RATE_75 = 0b110,
      RATE_RESERVED = 0b111
   };

   enum eMeasurementMode {
      MM_NORMAL = 0b00,   //Default value
      MM_POSITIVE = 0b01,
      MM_NEGATIVE = 0b10,
      MM_RESERVED = 0b11
   };

   enum eMeasurementSamples {
      MA_1 = 0b00,   //Default value
      MA_2 = 0b01,
      MA_4 = 0b10,
      MA_8 = 0b11
   };

   BBoneBlackMC5883L();

   bool setGain( const BBoneBlackMC5883L::eGainValue & gainValue );
   bool setOperationMode( const BBoneBlackMC5883L::eOperatingMode & opMode );
   bool setI2CSpeed( const BBoneBlackMC5883L::eI2CSpeed speed );
private:
   CPBBoneBlackI2C mI2CDevice;
   BBoneBlackMC5883L::eGainValue mCurrentGain = BBoneBlackMC5883L::RANGE_1_3GA;
   BBoneBlackMC5883L::eOperatingMode mCurrentOpMode = BBoneBlackMC5883L::OPMODE_SINGLE;
   BBoneBlackMC5883L::eI2CSpeed mCurrentSpeed = BBoneBlackMC5883L::SPEED_LOW;
};

#endif // BBONEBLACKMC5883L_HPP
