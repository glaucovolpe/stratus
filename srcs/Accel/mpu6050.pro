

TARGET = mpu6050
#INSTALLS = target

#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../../build/Acell
MOC_DIR = ../../build/Acell
OBJECTS_DIR = ../../build/Acell

SOURCES += main.cpp \
    mpu6050.cpp

HEADERS += \
    mpu6050.h


