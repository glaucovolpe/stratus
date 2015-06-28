#include <iostream>
#include "serial.h"
#include "gps.h"

using namespace std;

int main()
{
    char * data;


    SERIAL serial(1,2);
    GPS gps;
for (int x=0;x<800;x++){
	data = serial.Read();
//	usleep(1000000);
	for(int i=0;data[i]!='\n';i++){
		cout<<data[i];
	}
	cout << endl;

	gps.dataEdit(data,data[0]);

//	cout<<"Alt: "<< gps.getAlt() <<endl;
//	cout<<"Lon: "<< gps.getLon() <<endl;
//	cout<<"Lat: "<< gps.getLat() <<endl;
//        cout<< gps.get() <<endl;
}

    return 0;
}
