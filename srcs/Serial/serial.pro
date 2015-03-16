

TARGET = serial
#INSTALLS = target

#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../../build/Serial
MOC_DIR = ../../build/Serial
OBJECTS_DIR = ../../build/Serial

SOURCES += main.cpp \
    serial.cpp

HEADERS += \
    serial.h


