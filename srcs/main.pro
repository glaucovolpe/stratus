
TARGET = gps
#INSTALLS = target

#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../build
MOC_DIR = ../build

OBJECTS_DIR = ../build

SOURCES += main.cpp \
	GPS/gps.cpp  \
	Serial/serial.cpp\
	I2C/i2c.cpp


HEADERS += \
    	   GPS/gps.h  \
    	   Serial/serial.h

INCLUDEPATH += Serial\
	GPS\
	I2C\
	Accel\
