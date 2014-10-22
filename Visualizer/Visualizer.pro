#-------------------------------------------------
#
# Project created by QtCreator 2014-09-20T20:31:58
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Visualizer
TEMPLATE = app

INCLUDEPATH+=../lib
INCLUDEPATH+=../lib/references/glm
INCLUDEPATH+=../

LIBS += -L$$PWD/../shared  -L$$PWD/../lib -Wl,-rpath $$PWD/../shared   -lshared -Wl,-rpath $$PWD/../lib -lmOpenGL

#LIBS += -L$$PWD/../shared -Wl,-rpath,/home/mmendes/workspace/mOpenGL/lib -lmOpenGL


#C++11
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        MainWindow.cpp \
    WindowGL.cpp \
    mOpenGLWidget.cpp \
    IGLApp.cpp \
    OneRect.cpp

HEADERS  += MainWindow.h \
    WindowGL.h \
    mOpenGLWidget.h \
    IGLApp.h \
    OneRect.h

FORMS    += MainWindow.ui
