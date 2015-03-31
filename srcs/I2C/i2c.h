#ifndef I2C
class I2C
{

private:
    int I2CBus, I2CAddress;
    unsigned char Buffer[];

public:
    I2C(int bus, int address);
    char* ReadAll();
    int  WriteByte(char address, char value);
};

#endif I2C
