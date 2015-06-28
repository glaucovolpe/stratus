#include <iostream>
#include "serial.h"
#include <unistd.h>

using namespace std;

int main()
{
     char * data;


    SERIAL serial(1,2);
    usleep(1000000);
    //cout<<"conectando"<<endl;
    //data = serial.Read();

  for(int j=0;j<5;j++){
	data = serial.Read();
	if(data){
  	  for(int i=0;(i<100)&(data[i]!='\n');i++){
          cout<<data[i];
	  }
	cout<<"\n";
      }
//if(data[i]='\n')
//	else  usleep(1000000);
    }
//cout<<"\n";
    return 0;
}
