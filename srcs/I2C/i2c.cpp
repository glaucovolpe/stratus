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

#define SIZE_PATH 0x10
#define MAX_BUS 0x75


using namespace std;

I2C::I2C(unsigned int bus,unsigned char address) {
        this->file=-1;
	this->i2cBus = bus;
	this->i2cAddress = address;
	this->open();
}

int I2C::open(){

    char namebuf[SIZE_PATH];
    snprintf(namebuf, sizeof(namebuf), "/dev/i2c-%d", this->i2cBus);

    if ((this->file = ::open(namebuf, O_RDWR)) < 0){
            cout << "Failed to open I2C device!" << namebuf << " Couldn't fid /dev/i2c-"<< this->i2cBus << endl;
            return 0;
    }
    if (ioctl(this->file, I2C_SLAVE, this->i2cAddress) < 0){
            cout << "I2C_SLAVE "<< this->i2cAddress << this->i2cAddress << " doesn't exists" << endl;
            return 0;
    }
return 1;
}

unsigned char * I2C::readBytes(unsigned char regAddress,unsigned int numBytes){

    unsigned char buffer[numBytes];
    buffer[0]=  regAddress;
    if(::write(this->file, buffer , 1) !=1){
        cout << "Failed to Reset Address" << endl;
    }

    int bytesRead = read(this->file, buffer, numBytes);
    if (bytesRead == -1){
        cout << "Failure to read Byte Stream" << endl;
    }

    return buffer;
}



unsigned char I2C::readByte(unsigned char regAddress){
    unsigned char buffer[1] = { regAddress };
    if(::write(this->file, buffer , 1) !=1){
        cout << "Failed to Reset Address" << endl;
    }

    int bytesRead = read(this->file, buffer, 1);
    if (bytesRead == -1){
        cout << "Failure to read Byte Stream" << endl;
    }

//   memcpy(data, this->buffer,1);

    return buffer[0];
}


int I2C::writeByte(unsigned char regAddress,unsigned char value){
    unsigned char buffer[2];
        buffer[0] = regAddress;
        buffer[1] = value;
    if (::write(this->file, buffer, 2) != 2) {
        cout << "Failure to write values to I2C Device address." << endl;
        return(3);
    }

    return 0;
}

void I2C::close(){
	::close(this->file);
	this->file = -1;
}

I2C::~I2C(){
	if(file!=-1) this->close();
}
