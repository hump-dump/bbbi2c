#ifndef CPBBONEBLACKI2C_HPP
#define CPBBONEBLACKI2C_HPP


class CPBBoneBlackI2C
{
public:
   CPBBoneBlackI2C();
   bool openDevice();
   bool closeDevice();
private:
   int mI2CHandle = -1;
};

#endif // CPBBONEBLACKI2C_HPP
