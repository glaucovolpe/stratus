

TARGET = gps
#INSTALLS = target

#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../build
MOC_DIR = ../build
OBJECTS_DIR = ../build

SOURCES += main.cpp \
    	   gps.cpp  \	
	   ../Serial/serial.cpp


HEADERS += \
    	   gps.h  \
    	   ../Serial/serial.h

INCLUDEPATH += ../Serial

