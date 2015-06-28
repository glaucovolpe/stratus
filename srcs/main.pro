
TARGET = Telemetria
#INSTALLS = target

#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../build
MOC_DIR = ../build

OBJECTS_DIR = ../build

SOURCES += 	main.cpp \
		GPS/gps.cpp  \
		Serial/serial.cpp \
		I2C/i2c.cpp \
		Accel/mpu6050.cpp \
		adxl345.cpp

HEADERS +=     	GPS/gps.h  \
    		Serial/serial.h \
		I@C/i2c.h \
		Accel/mpu6050.h \
		adxl345.h

INCLUDEPATH += 	Serial\
		GPS\
		I2C\
		Accel\
