
#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T21:48:26
#
#-------------------------------------------------
CONFIG+=console

QT       += core gui

#INCLUDEPATH+=./glew/include
INCLUDEPATH+=./References/glm
INCLUDEPATH+=./
INCLUDEPATH+=./shapes


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myOPenGL
TEMPLATE = app


QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
    shapes/Rectangle3D.cpp \
    shapes/Triangle.cpp \
    shapes/Vector4.cpp \
    shaders/ColorShader.cpp \
    EngineGL.cpp \
    MainWindow.cpp \
    WindowGL.cpp \
    utilities/RefArray.cpp \
    shapes/ITopology.cpp \
    utilities/EngineException.cpp \
    shapes/IMaterial.cpp \
    utilities/IObservable.cpp \
    shapes/IShapeDynamic.cpp \
    shapes/Vector3.cpp \
    shapes/DynamicShapeComposed.cpp

HEADERS  += \
    shapes/Rectangle3D.h \
    shapes/BufferSelect.h \
    globals.h \
    shapes/Vector4.h \
    shapes/Vector3.h \
    shapes/Triangle.h \
    shapes/ShapeBindInfo.h \
    shapes/SubVector.h \
    shaders/ColorShader.h \
    EngineGL.h \
    WindowGL.h \
    MainWindow.h \
    shapes/Vector3.h \
    ArrayColorMap.h \
    Camera.h \
    ICamera.h \
    opointer.h \
    ui_mainwindow.h \
    utilities/RefArray.h \
    shapes/ITopology.h \
    utilities/EngineException.h \
    shapes/IShape.h \
    shapes/Shape.h \
    utilities/IArray.h \
    shapes/IMaterial.h \
    utilities/IObservable.h \
    shapes/IShapeDynamic.h \
    shapes/IShapeWatcher.h \
    shapes/ShapeSimpleComposed.h \
    shapes/ShapeDynamicComposed.h

FORMS    += mainwindow.ui

INCLUDEPATH+=./
