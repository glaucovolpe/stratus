
TARGET = accel
#INSTALLS = target

#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../build
MOC_DIR = ../build

OBJECTS_DIR = ../build

SOURCES += 	main.cpp \
		../I2C/i2c.cpp \
		mpu6050.cpp \
		adxl345.cpp

HEADERS +=     	../I2C/i2c.h \
		mpu6050.h \
		adxl345.h

INCLUDEPATH += 	../I2C 		 
