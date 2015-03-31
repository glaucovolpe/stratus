#include <iostream>
#include "serial.h"
#include "gps.h"
#include "i2c.h"
#include "adxl345.h"

using namespace std;

int main()
{
    char * data;


	SERIAL serial(1,4);
	GPS gps;
	ADXL345 acell;
	data = serial.Read();
//	usleep(1000000);
	for(int i=0;i<350;i++){
       cout<<data[i];
	}
	gps.dataEdit(data,350);
//delete[] data;
    return 0;
}
