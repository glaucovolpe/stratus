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
#include <i2c.h>


#define MAX_BUS 0x75


using namespace std;

I2C::I2C(int bus, int address) {
    I2CBus = bus;
    I2CAddress = address;

//    WriteByte(PWR_MGMT_1,0x00);
//    WriteByte(ACCEL_CONFIG,0x00);
//    cout << "congig 2 de 2" << endl;
}

char * I2C::ReadAll(){

    char namebuf[MAX_BUS];
    char * data = new char[14];

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

    return data;
}





int I2C::WriteByte(char address, char value){

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




I2C::~I2C() {
    // MPU6050's destructor
}
