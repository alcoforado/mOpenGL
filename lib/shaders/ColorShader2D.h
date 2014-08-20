#pragma once

#include <globals.h>
//#include "VectorFunction4x4.h"
#include <QOpenGLContext>
#include <GL.h>
#include <framework/Vector4.h>
#include <framework/Vector2.h>
#include <framework/GLProgram.h>
#include <framework/BuffersMngr.h>


class ColorShader2D
{

public:
    struct VerticeData {
        Vector2 Position;
        Vector4 Color;
    };

private:
    GL &_gl;
    GLProgram _program;
    BuffersMngr<VerticeData>  _mngr;
public:

   ColorShader2D(GL &gl);


    BuffersMngr<ColorShader2D::VerticeData>& GetManager() {return _mngr;}



    void Draw();






};



