

TARGET = gps
#INSTALLS = target

#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../../build/GPS
MOC_DIR = ../../build/GPS
OBJECTS_DIR = ../../build/GPS

SOURCES += main.cpp \
    	   gps.cpp  \	
	   ../Serial/serial.cpp


HEADERS += \
    	   gps.h  \
    	   ../Serial/serial.h

INCLUDEPATH += ../Serial
