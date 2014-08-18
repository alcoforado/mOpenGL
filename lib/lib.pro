
#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T21:48:26
#
#-------------------------------------------------
CONFIG+=console

QT       += core gui

#INCLUDEPATH+=./glew/include
INCLUDEPATH+=./references/glm
INCLUDEPATH+=../
INCLUDEPATH+=./shapes
INCLUDEPATH+=$$PWD/../shared
INCLUDEPATH+=$$PWD/shapes2D

LIBS += -Wl,-rpath $$PWD/../shared  -lshared
LIBPATH += $$PWD/../shared

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myOPenGL
TEMPLATE = app


QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
    shapes/Rectangle3D.cpp \
    shapes/Triangle.cpp \
    MainWindow.cpp \
    WindowGL.cpp \
    utilities/RefArray.cpp \
    shapes/ITopology.cpp \
    utilities/EngineException.cpp \
    utilities/IObservable.cpp \
    shapes/DynamicShapeComposed.cpp \
    shapes/ShapeRoot.cpp \
    SphericMovement.cpp \
    utilities/regionarray.cpp \
    shaders/ColorShader2D.cpp \
    shaders/GLProgram.cpp \
    GL.cpp \
    shapes2D/ITopology2D.cpp \
    shapes2D/Rect2D.cpp \
    shapes2D/Shape2D.cpp \
    shaders/VertexArrayAttribute.cpp \
    framework/GLBuffer.cpp \
    framework/GLProgram.cpp \
    framework/VertexArrayAttribute.cpp \
    framework/IMaterial.cpp \
    framework/ShapeBatch.cpp \
    framework/Vector2.cpp \
    framework/Vector3.cpp \
    framework/Vector4.cpp

HEADERS  += \
    shapes/Rectangle3D.h \
    globals.h \
    shapes/Triangle.h \
    WindowGL.h \
    MainWindow.h \
    ArrayColorMap.h \
    Camera.h \
    ICamera.h \
    opointer.h \
    utilities/RefArray.h \
    shapes/ITopology.h \
    utilities/EngineException.h \
    shapes/Shape.h \
    utilities/IArray.h \
    utilities/IObservable.h \
    shapes/ShapeSimpleComposed.h \
    shapes/ShapeDynamicComposed.h \
    shapes/ShapeRoot.h \
    SphericMovement.h \
    shaders/ColorShader2D.h \
    utilities/regionarray.h \
    GL.h \
    shapes2D/ITopology2D.h \
    shapes2D/Rect2D.h \
    shapes2D/Shape2D.h \
    shapes/BuffersMngr.h \
    framework/GLBuffer.h \
    framework/GLProgram.h \
    framework/VertexArrayAttribute.h \
    utilities/BufferSelect.h \
    utilities/SubVector.h \
    framework/IMaterial.h \
    framework/IShape.h \
    framework/IShapeWatcher.h \
    framework/ShapeBatch.h \
    framework/Vector2.h \
    framework/Vector3.h \
    framework/Vector4.h


FORMS    += mainwindow.ui

INCLUDEPATH+=./



glsl.target = .buildfile.h
glsl.commands= cd $$PWD/glsl;make
glsl.depends= FORCE
QMAKE_EXTRA_TARGETS+= glsl
PRE_TARGETDEPS+=.buildfile.h




OTHER_FILES += \
    glsl/Color2D.frag \
    glsl/Color2D.vsh \
    glsl/Color2D_PS.glsl \
    glsl/Color2D_VS.glsl
