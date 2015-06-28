#ifndef GPS_H

#define GPS_H

class GPS
{

private:
float LATITUDE, LONGITUDE, SPEED, ALTITUDE, DIRECTION, TIME;
	void setAlt(float alt){ALTITUDE = alt;}
	void setLat(float lat){LATITUDE = int(lat/100)+(lat-int(lat/100)*100)/60;}
	void setLon(float lon){LONGITUDE = int(lon/100)+(lon-int(lon/100)*100)/60;}
	void setSpd(float spd){SPEED = spd*1.852;}
	void setTim(float tim){TIME = tim;}
	void setDir(float dir){DIRECTION = dir;}
public:
	GPS();
	int dataEdit(char * data, int sizeOfData);
	float getAlt(void){return ALTITUDE;}
	float getLat(void){return LATITUDE;}
	float getLon(void){return LONGITUDE;}
	float getSpd(void){return SPEED;}
	float getTime(void){return TIME;}
	unsigned int checkSum(char * data, int sizeOfData);

	virtual ~GPS();
};

#endif
