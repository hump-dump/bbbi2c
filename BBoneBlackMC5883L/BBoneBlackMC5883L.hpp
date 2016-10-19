#ifndef BBONEBLACKMC5883L_HPP
#define BBONEBLACKMC5883L_HPP

#define I2C_MC5883L_ADDR 0x1E  // 3 Axis Magnetometer	Honeywell MC5883L

class BBoneBlackMC5883L
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

   // Configuration Register A = eMeasurementSamples | eDataOutputRate | eMeasurementMode

   enum eMeasurementSamples {
      MA_1 = 0b0000000,   //Default value
      MA_2 = 0b0100000,
      MA_4 = 0b1000000,
      MA_8 = 0b1100000
   };

   enum eDataOutputRate {
      RATE_0_75 = 0b00000,
      RATE_1_5 = 0b00100,
      RATE_3 = 0b01000,
      RATE_7_5 = 0b01100,
      RATE_15 = 0b10000,   // Default value
      RATE_30 = 0b10100,
      RATE_75 = 0b11000,
      RATE_RESERVED = 0b11100
   };

   enum eMeasurementMode {
      MM_NORMAL = 0b00,   //Default value
      MM_POSITIVE = 0b01,
      MM_NEGATIVE = 0b10,
      MM_RESERVED = 0b11
   };

   BBoneBlackMC5883L();

   bool setGain( const BBoneBlackMC5883L::eGainValue & gainValue );
   bool setOperationMode( const BBoneBlackMC5883L::eOperatingMode & opMode );
   bool setI2CSpeed( const BBoneBlackMC5883L::eI2CSpeed & speed );
   bool setMeasurementMode( const BBoneBlackMC5883L::eMeasurementMode & measurementMode );
   bool setDataOutputRate( const BBoneBlackMC5883L::eDataOutputRate & dataOutputRate );
   bool setMeasurementSamples( const BBoneBlackMC5883L::eMeasurementSamples & measurementSamples );
private:
   BBoneBlackMC5883L::eGainValue mCurrentGain = BBoneBlackMC5883L::RANGE_1_3GA;
   BBoneBlackMC5883L::eOperatingMode mCurrentOpMode = BBoneBlackMC5883L::OPMODE_SINGLE;
   BBoneBlackMC5883L::eI2CSpeed mCurrentSpeed = BBoneBlackMC5883L::SPEED_LOW;
   BBoneBlackMC5883L::eMeasurementSamples mCurrentMeasurementSamples = BBoneBlackMC5883L::MA_1;
   BBoneBlackMC5883L::eDataOutputRate mCurrentDataOutputRate = BBoneBlackMC5883L::RATE_15;
   BBoneBlackMC5883L::eMeasurementMode mCurrentMeasurementMode =BBoneBlackMC5883L::MM_NORMAL;
};

#endif // BBONEBLACKMC5883L_HPP
