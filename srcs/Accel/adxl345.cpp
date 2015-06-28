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
#include <adxl345.h>


#define MAX_BUS 0x75



using namespace std;

ADXL345::ADXL345(int bus, int address) {
    I2CBus = bus;
    I2CAddress = address;

    //WriteByte(PWR_MGMT_1,0x00);
    //WriteByte(ACCEL_CONFIG,0x00);
    cout << "congig 2 de 2" << endl;

    //ReadAll();

}
   //    this->accX = HEXtoINT(ACCEL_XOUT_H, ACCEL_XOUT_L);
    //    this->accY = HEXtoINT(ACCEL_YOUT_H, ACCEL_YOUT_L);
    //    this->accZ = HEXtoINT(ACCEL_ZOUT_H, ACCEL_ZOUT_L);
    //    this->gyroX =HEXtoINT(GYRO_XOUT_H, GYRO_XOUT_L);
    //    this->gyroY =HEXtoINT(GYRO_YOUT_H, GYRO_YOUT_L);
    //    this->gyroZ =HEXtoINT(GYRO_ZOUT_H, GYRO_ZOUT_L);
//ADXL345::HEXtoINT(int OUT_H, int OUT_L){
//    short temp = Buffer[OUT_H];
//    temp = (temp<<8) | Buffer[OUT_L];
//    return temp;
//}


ADXL345::~ADXL345() {
    // MPU6050's destructor
}

