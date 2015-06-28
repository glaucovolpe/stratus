#ifndef ADXL345_H

#define ADXL345_H
#define MPU6050_I2C_BUFFER 0x80

class ADXL345
{

private:
    int I2CBus, I2CAddress;
    unsigned char Buffer[MPU6050_I2C_BUFFER];
    int setUSER_CTRL();
    int  WriteByte(char address, char value);

    int accX;
    int accY;
    int accZ;
    int gyroX;
    int gyroY;
    int gyroZ;

public:
    ADXL345(int bus, int address);
    char* ReadAll();

    int getAccX() { return accX; }
    int getAccY() { return accY; }
    int getAccZ() { return accZ; }
    int getGyroX() { return gyroX; }
    int getGyroY() { return gyroY; }
    int getGyroZ() { return gyroZ; }

    virtual ~ADXL345();

};

#endif // ADXL345_H
