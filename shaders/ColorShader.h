#pragma once

#include <shapes/ShapesMngr.h>
#include <d3dcompiler.h>
#include <shapes/AbstractShape.h>
#include <globals.h>
//#include "VectorFunction4x4.h"
#include <QOpenGLContext>
#include <EngineGL.h>
#include <Vector4.h>

class ColorShader
{
	EngineGL *_gl;
	ShapesMngr _mngr;	

public:
	ColorShader(EngineGL *gl);
	 void Clear();
	 void AddShape(AbstractShape* sh,VectorFunction4x4 *vf);
	 void SetWorldViewProj(glm::mat4 &worldViewProj);
	 void SetContext(QOpenGLContext *context);
	 void UpdateGeometryBuffers();
	 void draw();
     void test();
};



