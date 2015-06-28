
TARGET = i2c
#INSTALLS = target

#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../build
MOC_DIR = ../build

OBJECTS_DIR = ../build

SOURCES += 	main.cpp \
		i2c.cpp 

HEADERS +=	i2c.h \

INCLUDEPATH +=	I2C
		
