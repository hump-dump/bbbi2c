#ifndef BBONEBLACKBMP085_HPP
#define BBONEBLACKBMP085_HPP

#include "CPDebugMessage.hpp"
#include "CPBBoneBlackI2C.hpp"
#include <cstdint>

#define I2C_BMP085_ADDR 0x77 // Barometer + Thermometer	Bosch BMP085

class BBoneBlackBMP085
   : public CPDebugMessage
{
public:
   BBoneBlackBMP085();
   void init();
   bool getTemperature( float & temperature );
protected:

   struct sBMP085CalibrationData {
      int16_t AC1 = 0;
      int16_t AC2 = 0;
      int16_t AC3 = 0;
      uint16_t AC4 = 0;
      uint16_t AC5 = 0;
      uint16_t AC6 = 0;
      int16_t B1 = 0;
      int16_t B2 = 0;
      int16_t MB = 0;
      int16_t MC = 0;
      int16_t MD = 0;
      bool isActual = false;
   };

   void readCalibrationData();
   bool readUncompensatedTemperature( long & UncompensatedTemperature );
private:
   CPBBoneBlackI2C mI2CDevice;
   sBMP085CalibrationData mCalibrationData;
};

#endif // BBONEBLACKBMP085_HPP
