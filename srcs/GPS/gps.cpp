/*******************************************************************************\
    This code read one line data from a gps(GTPA010) receiver and stores it in
 memmory for telemetry use.

  Created on 27 March 2015
  By Glauco Volpe <glauco@aluno.unb.br>
\*******************************************************************************/


#include<iostream>
#include<cstdlib>
#include<gps.h>
#include<string>
#include<sstream>

using namespace std;


GPS::GPS() {

}


unsigned int GPS::checkSum(char *data, int sizeOfData){
    	int checksum = 0;
    	for(int k=1;k<sizeOfData;k++)
    	{
              	checksum ^= data[k];
		cout<< data[k];
    	}
 
	cout<<endl;
//delete[] data;
    	return(checksum);
}

int GPS::dataEdit(char *data, int sizeOfData){
//int j=0;
int c=0;
int commas[20];
//unsigned int check;
//stringstream ss;
double number;
string str;

/*
*	$GPRMC,225446,A,4916.45,N,12311.12,W,000.5,054.7,191194,020.3,E*68
*
*	1 = Time of fix 22:54:46 UTC
*     	2 = Navigation receiver warning A = OK, V = warning
*     	3 = Latitude 49 deg. 16.45 min
*	4 = Lattitude dir  North
*     	5 = Longitude 123 deg. 11.12 min
*	6 = Longitude dir West
*    	7 = Speed over ground, Knots
*     	8 = Course Made Good, True
*     	9 = Date of fix  19 November 1994
*    	10 = Magnetic variation 20.3 deg East
*     	11 = mandatory checksum
*/
	if(data[3]=='R'){
		for(int i=3;(i<100) & (data[i]!='\n');i++){
			if(data[i]==','){
                        	commas[c]=i;
                                c++;
                        }
                        if(data[i]=='*'){
//Tempo
                                str.append(data+1,commas[0], commas[1]-commas[0]-1);
                                number = atof(str.c_str());
                                setTim(number);
                                cout<<"Time: "<<number<<endl;
                                str="";
//Latitude
                                str.append(data+1,commas[2], commas[3]-commas[2]-1);
                                number = atof(str.c_str());
                                if(data[commas[3]+1]=='N')
	                                number *= -1;
                                setLat(number);
                                cout<<"Latitude: "<<getLat()<<endl;
                                str="";

//Longitude
                                str.append(data+1,commas[4], commas[5]-commas[4]-1);
                                number = atof(str.c_str());
                                if(data[commas[5]+1]=='E')
                                        number *= -1;
				setLon(number);
                                cout<<"Longitude: "<<getLon()<<endl;
                                str="";

//velocidade
                                str.append(data+1,commas[6], commas[7]-commas[6]-1);
                                number = atof(str.c_str());
                                setSpd(number);
				number = getSpd();
                                cout<<"Velocidade: "<<number<<endl;
                                str="";
//direção
                                str.append(data+1,commas[7], commas[8]-commas[7]-1);
                                number = atof(str.c_str());
                                setDir(number);
                                cout<<"Dire��o: "<<number<<endl;
                                str="";
                        }
             	}
	}

/*
*	$GPGGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh
*	1  = UTC of Position
*	2  = Latitude
*	3  = N or S
*	4  = Longitude
*	5  = E or W
*	6  = GPS quality indicator (0=invalid; 1=GPS fix; 2=Diff. GPS fix)
*	7  = Number of satellites in use [not those in view]
*	8  = Horizontal dilution of position
*	9  = Antenna altitude above/below mean sea level (geoid)
*	10 = Meters  (Antenna height unit)
*	11 = Geoidal separation (Diff. between WGS-84 earth ellipsoid and mean sea level. -=geoid is below WGS-84 ellipsoid)
*	12 = Meters  (Units of geoidal separation)
*	13 = Age in seconds since last update from diff. reference station
*	14 = Diff. reference station ID#
*	15 = Checksum
*/
	if(data[4]=='G'){
		for(int i=4;(i<100) & (data[i]!='\n');i++){
			if(data[i]==','){
				commas[c]=i;
				c++;
			}
			if(data[i]=='*'){
//Tempo
				str.append(data+1,commas[0], commas[1]-commas[0]-1);
                        	number = atof(str.c_str());
                        	setTim(number);
                        	cout<<"Tempo: "<<number<<endl;
                        	str="";
//Latitude
				str.append(data+1,commas[1], commas[2]-commas[1]-1);
				number = atof(str.c_str());
				if(data[commas[2]+1]=='N')
					number *= -1;
				setLat(number);
				cout<<"Latitude: "<<getLat()<<endl;
				str="";
//Longitude
				str.append(data+1,commas[3], commas[4]-commas[3]-1);
				number = atof(str.c_str());
				if(data[commas[4]+1]=='E')
					number *= -1;
				setLon(number);
				cout<<"Longitude: "<<getLon()<<endl;
				str="";

//Antena Altitude
//					str.append(data+1,commas[3], commas[2]-commas[1]-1);
//                                        cout << str;
//                                        number = atof(str.c_str());
//                                        setAlt(number);
			}
		}
	}

return 0;
}

//void setLon(float lon)
//{
//	lon = aux+(lon-int(lon/100)*100)/60;
//this->
//}

GPS::~GPS(){
	//GPS's destructor
}
