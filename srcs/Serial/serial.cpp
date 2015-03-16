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
#define MAX_BUFF 500

using namespace std;

SERIAL::SERIAL(int baud, int bus) {
	baud = bus;
	baud++;
    //int serialPort = bus;
}

char * SERIAL::Read(){
    int serialport = 4;
    char namebuf[14];
    char * data = new char[MAX_BUFF] ;
    struct termios options;
//    int wait_flag, STOP;

    snprintf(namebuf, sizeof(namebuf), "/dev/ttyO%d", serialport);
    int file;

    if ((file = open(namebuf, O_RDWR | O_NOCTTY | O_NDELAY)) < 0){
            cout << "Failed to open serial port on " << endl;
	    perror("open_port: Unable to open /dev/ttyf1 - ");
	return 0;
    }


    	fcntl(file, F_SETFL, 0);

	tcgetattr(file, &options);
        cfsetispeed(&options, B4800);
        cfsetospeed(&options, B4800);
	//options.c_lflag |= (ICANON | ECHO | ECHOE);
	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	//options.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
        //options.c_iflag = IGNPAR | ICRNL;
        //options.c_oflag = 0;
        //options.c_lflag = ICANON;
        //options.c_cc[VMIN]=1;
        //options.c_cc[VTIME]=0;
        //tcflush(file, TCIFLUSH);
	tcsetattr(file, TCSANOW, &options);
	usleep(1300000);
	//data = read(file, buffer, sizeof(buffer));
	//while (STOP==0) {
        //  printf(".\n");usleep(100000);
          /* after receiving SIGIO, wait_flag = FALSE, input is available
             and can be read */
        //  if (wait_flag==0) { 
        //    bytesRead = read(file,Buffer,255);
        //    bufff[bytesRead]=0;
        //    printf(":%s:%d\n", buffer, bytesRead);
        //    if (bytesRead==1) STOP=1; /* stop loop if only a CR was input */
        //    wait_flag = 1;      /* wait for new input */
        //  }
	//}

   int bytesRead = read(file, this->Buffer, MAX_BUFF);

	cout<<"number of bytes readed: "<<bytesRead<<endl;
//	for(int i=0;i<bytesRead;i++)
//	{
//	cout<<Buffer[i];
//	}
	cout<<" "<<endl;
	//tcflush(file, TCIFLUSH);
    close(file);

     memcpy(data, Buffer,bytesRead);

    return data;
}



int SERIAL::Write(){

    return 0;
}




SERIAL::~SERIAL() {
    // MPU6050's destructor
}

