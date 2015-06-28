#include <iostream>
#include "i2c.h"
#include "math.h"

using namespace std;

int main()
{
	float aux;
	float acc[3];
        unsigned char * data;
	cout << "inicializando device...";
	I2C accel(2,0x68);
	cout << "   done"<< endl;
	cout << (unsigned int)accel.readByte(0x00) << endl;
	accel.writeByte(0x6b,0);
//        accel.writeByte(0x0d,0);
//        accel.writeByte(0x0e,0);
//        accel.writeByte(0x0f,0);

	data = accel.readBytes(0x43,6);
	for (int i=0;i<3;i++){
	acc[i] = /*(int) data[i*2+1]+*/((int)data[i*2]);
	//acc[i]= aux-257*128;
	//cout << aux-(257*128)  << " ";
	}
	//aux = acc[0]*acc[0]+acc[1]*acc[1]+acc[2]*acc[2];
	//aux = sqrt(aux);
	//cout << endl << aux << endl;
	//aux = sqrt(aux);
	cout<< acc[0] <<" "<< acc[1] << " " << acc[2]<<endl;
//    MPU6050 accelerometer(1,0x68);
//    data = accelerometer.ReadAll();

//    for(int i=0;i<14;i++){
//        cout<<uppercase<< data[i]<<"\t";
//    cout<<"\n";
//    }

    return 0;
}
