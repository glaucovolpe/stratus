#ifndef SERIAL_H

#define SERIAL_H

#define SERIAL_BUFFER 300
 
class SERIAL
{

private:
    int I2CBus, I2CAddress;
    unsigned char Buffer[SERIAL_BUFFER];

public:
    SERIAL(int bus, int address);
    char* Read();
    int Write();
    virtual ~SERIAL();
    
};

#endif // SERIAL_H
