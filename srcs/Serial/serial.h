#ifndef SERIAL_H

#define SERIAL_H

#define MAX_BUFFER 200

class SERIAL
{

private:
    int serialBus, serialBaud;
    char buffer[MAX_BUFFER];
    int file;

public:
    SERIAL(int bus, int address);
    int open();
    char* Read();
    int Write(unsigned char msg);
    void close();
    virtual ~SERIAL();
    
};

#endif // SERIAL_H
