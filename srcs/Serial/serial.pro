
TARGET = serial
#INSTALLS = target

#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../build
MOC_DIR = ../build

OBJECTS_DIR = ../build

SOURCES += 	main.cpp \
		serial.cpp \

HEADERS += serial.h \
#INCLUDEPATH +=	../Serial \
