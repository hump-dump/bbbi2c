#ifndef CPBBONEBLACKI2C_HPP
#define CPBBONEBLACKI2C_HPP

#include <cstdint>

#define I2C_GYRO_ADDR   0x69 // 3 Axis Gyro	ST Microelectronics L3G4200D
#define I2C_BMP085_ADDR 0x77 // Barometer + Thermometer	Bosch BMP085
class CPBBoneBlackI2C
{
public:
   CPBBoneBlackI2C();
   bool openDevice();
   bool closeDevice();
   bool initGyro();
   bool initBMP085();
   int32_t readTemperature();
private:
   int mI2CHandle = -1;
};

#endif // CPBBONEBLACKI2C_HPP
