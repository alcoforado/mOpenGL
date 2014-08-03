#pragma once

#include <globals.h>
//#include "VectorFunction4x4.h"
#include <QOpenGLContext>
#include <EngineGL.h>
#include <Vector4.h>
#include <Vector2.h>
#include <shapes/ShapeRoot.h>
class ColorShader2D
{
	EngineGL *_gl;
    ShapeRoot _root;

public:
    struct VerticeData {
        Vector2 Position;
        Vector4 Color;
    };

    void AddShape(Ishape<ColorShader2D::VerticeData> *shape)
    {
        _root.AddShape(*shape);
    }

};



