#pragma once

#include <globals.h>
//#include "VectorFunction4x4.h"
#include <QOpenGLContext>
#include <framework/GL.h>
#include <framework/Vector4.h>
#include <framework/Vector2.h>
#include <framework/GLProgram.h>
#include <framework/BuffersMngr.h>
#include <shapes2D/Shape2D.h>
#include <framework/IMaterial.h>
#include <material/ArrayOfColors.h>



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

//types
public:
    typename IMaterial<VerticeData> IMaterial;
    typename ArrayOfColors<VerticeData> ArrayOfColors;

    class Shape: public Shape2D<VerticeData,ITopology2D,IMaterial>
    {
    public:
        Shape(ITopology2D &tp2D,IMaterial &mat)
            :Shape2D(tp2D,mat)
        {}

        virtual void write(IArray<VerticeData> &vertices, IArray<int> &indices)
        {
            ArraySelect<Vector2> verts(vertices,&VerticeData::Position);
            GetTopology().WriteTopology(verts,indices);
            GetMaterial().write(vertices);
        }
    };

public:

   ColorShader2D(GL &gl);


    BuffersMngr<ColorShader2D::VerticeData>& GetManager() {return _mngr;}

    Shape* CreateShape(ITopology2D &top,IMaterial &mat)
    {
        auto shape = new Shape(top,mat);


    }


    void Draw();



};



