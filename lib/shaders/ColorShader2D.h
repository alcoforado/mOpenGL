#pragma once

#include <globals.h>
//#include "VectorFunction4x4.h"
#include <QOpenGLContext>
#include <EngineGL.h>
#include <Vector4.h>
#include <Vector2.h>
#include <shapes/ShapesMngr.h>
class ColorShader2D
{

public:
    struct VerticeData {
        Vector2 Position;
        Vector4 Color;
    };

private:

    EngineGL *_gl;
    BuffersMngr<VerticeData>  _mngr;
public:

   ColorShader2D();


    BuffersMngr<ColorShader2D::VerticeData>& GetManager() {return _mngr;}


    void Draw();






};



