#ifndef CPBBONEBLACKI2C_HPP
#define CPBBONEBLACKI2C_HPP

#include <cstdint>

#include "CPDebugMessage.hpp"

#define I2C_GYRO_ADDR   0x69 // 3 Axis Gyro	ST Microelectronics L3G4200D
#define I2C_BMP085_ADDR 0x77 // Barometer + Thermometer	Bosch BMP085

class CPBBoneBlackI2C
   : public CPDebugMessage
{
public:

   struct sBMP085CalibrationData {
      short AC1 = 0;
      short AC2 = 0;
      short AC3 = 0;
      unsigned short AC4 = 0;
      unsigned short AC5 = 0;
      unsigned short AC6 = 0;
      short B1 = 0;
      short B2 = 0;
      short MB = 0;
      short MC = 0;
      short MD = 0;
   };

   CPBBoneBlackI2C();
   bool openDevice();
   bool closeDevice();
   bool writeByteData( const unsigned char & command, const unsigned char & value );
   bool initGyro();
   bool initBMP085();
   unsigned int readTemperature();
private:
   int mI2CHandle = -1;
   void readCalibrationData();
   sBMP085CalibrationData mCalibrationData;
};

#endif // CPBBONEBLACKI2C_HPP
