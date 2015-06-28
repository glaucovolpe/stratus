#ifndef I2C
class I2C
{

private:
    unsigned int i2cBus, i2cAddress;
    int file;

public:
    I2C(unsigned int bus, unsigned char regAddress);
    int open();
    unsigned char * readBytes(unsigned char regAddress,unsigned int numBytes);
    int  writeByte(unsigned char regAddress,unsigned char value);
    unsigned char readByte(unsigned char regAddress);
    void close();
    virtual ~I2C();
};

#endif I2C
