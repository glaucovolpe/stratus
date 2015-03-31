#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stropts.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <mpu6050.h>


#define MAX_BUS 0x75
#define ACCEL_CONFIG 0x1c

//#define ACCEL_XOUT_H 0x3b
//#define ACCEL_XOUT_L 0x3c
//#define ACCEL_YOUT_H 0x3d
//#define ACCEL_YOUT_L 0x3e
//#define ACCEL_ZOUT_H 0x3f
//#define ACCEL_ZOUT_L 0x40

//#define TEMP_OUT_H 0x41
//#define TEMP_OUT_L 0x42

//#define GYRO_XOUT_H 0x43
//#define GYRO_XOUT_L 0x44
//#define GYRO_YOUT_H 0x45
//#define GYRO_YOUT_L 0x46
//#define GYRO_ZOUT_H 0x47
//#define GYRO_ZOUT_L 0x48

#define USER_CTRL 0x6a
#define PWR_MGMT_1 0x6b
#define PWR_MGMT_2 0x6c


using namespace std;

MPU6050::MPU6050(int bus, int address) {
    I2CBus = bus;
    I2CAddress = address;

    WriteByte(PWR_MGMT_1,0x00);
    WriteByte(ACCEL_CONFIG,0x00);
    cout << "congig 2 de 2" << endl;

    ReadAll();

}
char * MPU6050::ReadAll(){

    char namebuf[MAX_BUS];
    char * data = new char[14] ;

    snprintf(namebuf, sizeof(namebuf), "/dev/i2c-%d", I2CBus);
    int file;

    if ((file = open(namebuf, O_RDWR)) < 0){
            cout << "Failed to open MPU6050 Sensor on " << namebuf << " I2C Bus" << endl;
            return 0;
    }
    if (ioctl(file, I2C_SLAVE, I2CAddress) < 0){
            cout << "I2C_SLAVE address " << I2CAddress << " failed..." << endl;
            return 0;
    }

    char buf[1] = { 0x00 };
    if(write(file, buf, 1) !=1){
        cout << "Failed to Reset Address in ReadAll " << endl;
    }

    int numberBytes = MPU6050_I2C_BUFFER;
    int bytesRead = read(file, this->Buffer, numberBytes);
    if (bytesRead == -1){
        cout << "Failure to read Byte Stream in readFullSensorState()" << endl;
    }
    close(file);

     memcpy(data, Buffer,14);
     
        if ((this->Buffer[0]!=0x81)){
            cout << "MAJOR FAILURE: DATA WITH MPU6050 HAS LOST SYNC!" << endl;
        }


    //    this->accX = HEXtoINT(ACCEL_XOUT_H, ACCEL_XOUT_L);
    //    this->accY = HEXtoINT(ACCEL_YOUT_H, ACCEL_YOUT_L);
    //    this->accZ = HEXtoINT(ACCEL_ZOUT_H, ACCEL_ZOUT_L);
    //    this->gyroX =HEXtoINT(GYRO_XOUT_H, GYRO_XOUT_L);
    //    this->gyroY =HEXtoINT(GYRO_YOUT_H, GYRO_YOUT_L);
    //    this->gyroZ =HEXtoINT(GYRO_ZOUT_H, GYRO_ZOUT_L);


    return data;
}


//int MPU6050::HEXtoINT(int OUT_H, int OUT_L){
//    short temp = Buffer[OUT_H];
//    temp = (temp<<8) | Buffer[OUT_L];
//    return temp;
//}



int MPU6050::WriteByte(char address, char value){

    char namebuf[MAX_BUS];
    snprintf(namebuf, sizeof(namebuf), "/dev/i2c-%d", I2CBus);
    int file;
    if ((file = open(namebuf, O_RDWR)) < 0){
            cout << "Failed to open MPU6050 Sensor on " << namebuf << " I2C Bus" << endl;
            return(1);
    }

    if (ioctl(file, I2C_SLAVE, I2CAddress) < 0){
            cout << "I2C_SLAVE address " << I2CAddress << " failed..." << endl;
            return(2);
    }

    char buffer[2];
        buffer[0] = address;
        buffer[1] = value;
    if ( write(file, buffer, 2) != 2) {
        cout << "Failure to write values to I2C Device address." << endl;
        return(3);
    }

    close(file);
    return 0;
}




MPU6050::~MPU6050() {
    // MPU6050's destructor
}

