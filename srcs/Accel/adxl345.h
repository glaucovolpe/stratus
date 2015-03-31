#ifndef MPU6050_H

#define MPU6050_H
#define MPU6050_I2C_BUFFER 0x80

class MPU6050
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
//    double theta;
//    double omega;
//    int  HEXtoINT(int OUT_H, int OUT_L);

public:
    MPU6050(int bus, int address);
    char* ReadAll();

    int getAccX() { return accX; }
    int getAccY() { return accY; }
    int getAccZ() { return accZ; }
    int getGyroX() { return gyroX; }
    int getGyroY() { return gyroY; }
    int getGyroZ() { return gyroZ; }
    virtual ~MPU6050();
    
};

#endif // MPU6050_H
