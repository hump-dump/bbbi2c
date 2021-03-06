#ifndef BBONEBLACKBMP085_HPP
#define BBONEBLACKBMP085_HPP

#include <cstdint>

#define I2C_BMP085_ADDR 0x77  // Barometer + Thermometer	Bosch BMP085
#define BMP085_OSS         0  // oversampling setting( ultra low power mode )

class BBoneBlackBMP085
{
public:
   BBoneBlackBMP085();
   void init();
   bool getTemperature( float & temperature );
   bool getPressure(long & pressure );
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
   bool readUncompensatedPressure( long & UncompensatedPressure );
private:
   sBMP085CalibrationData mCalibrationData;
};

#endif // BBONEBLACKBMP085_HPP
