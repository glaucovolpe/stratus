#include <iostream>
#include "mpu6050.h"

using namespace std;

int main()
{
    char * data;


    MPU6050 accelerometer(1,0x68);
    data = accelerometer.ReadAll();

    for(int i=0;i<14;i++){
        cout<<uppercase<< data[i]<<"\t";
    cout<<"\n";
    }

    return 0;
}
