#include <stdlib.h>
#include <iostream>
#include <serial.h>
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */



#define BAUDRATE B4800


using namespace std;

SERIAL::SERIAL(int baud, int bus) {
	this->file=-1;
	this->serialBus = bus;
	this->serialBaud = baud;
	this->open();
}

int SERIAL::open(){
        char namebuf[14];
	struct termios options;
	//int wait_flag, STOP;

	snprintf(namebuf, sizeof(namebuf), "/dev/ttyO%d", this->serialBus);

	if ((this->file = ::open(namebuf, O_RDWR | O_NOCTTY | O_NDELAY)) < 0){
		cout << "Failed to open serial port on "<< this->serialBus << endl;
//		perror("open_port: Unable to open /dev/ttyf1%d",this->serialbus);
		return 0;
	}

    	fcntl(file, F_SETFL, 0);

	tcgetattr(this->file, &options);
//        cfsetospeed(&options, B4800);
	options.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD | CLOCAL;
        options.c_lflag = ICANON | IGNCR;
        tcflush(this->file, TCIFLUSH);
	tcsetattr(this->file, TCSANOW, &options);
        read(this->file, this->buffer, MAX_BUFFER);
//	usleep(1000000);

    return 0;
}

char* SERIAL::Read(){


	int bytesRead = read(this->file, this->buffer, MAX_BUFFER);
	if (bytesRead<2)
	bytesRead = read(this->file, this->buffer, MAX_BUFFER);

//   cout<<"->"<<bytesRead<<"<-"<<endl;

//   cout<<"number of bytes readed: "<<bytesRead<<endl;

//   string str(this->buffer);
//   str.append(char(bytesRead));
//   return str;
   return this->buffer;
}



int SERIAL::Write(unsigned char msg){
//    write(this->file,)
    if(msg) cout <<"só um teste"<< endl ;
    return 0;
}

void SERIAL::close(){
	::close(this->file);
	this->file = -1;
}

SERIAL::~SERIAL() {
    if(file!=-1) this->close();
}

