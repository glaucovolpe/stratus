#include <iostream>
#include "serial.h"

using namespace std;

int main()
{
    char * data;


    SERIAL serial(1,4);
    //cout<<"conectando"<<endl;
    //data = serial.Read();

  //  for(int i=0;i<15;i++){
	data = serial.Read();
//	usleep(1000000);
	for(int i=0;i<500;i++){
        cout<<data[i];
//    cout<<"\n";
    }
	cout<<"\n";
    return 0;
}
