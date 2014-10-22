#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T21:48:26
#
#-------------------------------------------------
CONFIG+=console


QT = core gui opengl

INCLUDEPATH+=../lib
INCLUDEPATH+=../lib/references/glm
INCLUDEPATH+=../
INCLUDEPATH+=$$PWD/gtest-1.7.0/include

LIBS += -lpthread $$PWD/gtest-1.7.0/lib/.libs/libgtest.a  -L$$PWD/../shared  -L$$PWD/../lib -Wl,-rpath $$PWD/../shared   -lshared -Wl,-rpath $$PWD/../lib -lmOpenGL

#C++11
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    main.cpp

HEADERS += \
    testarrayfieldselector.h
