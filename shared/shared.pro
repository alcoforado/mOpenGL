#-------------------------------------------------
#
# Project created by QtCreator 2014-08-06T23:04:58
#
#-------------------------------------------------

QT       -= core gui

TARGET = shared
TEMPLATE = lib

DEFINES += SHARED_LIBRARY

SOURCES += \
    Exception.cpp \
    Path.cpp

HEADERS +=\
        shared_global.h \
    Exception.h \
    Path.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
