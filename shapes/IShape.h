#pragma once



#include <utilities/EngineException.h>
#include <utilities/IArray.h>
//class ShapesMngr;
//class ShapeBindInfo;
//class SceneMngr::Indices;
//class SceneMngr::Vertices;
template<class VertexData>
class IShape
{


public:
	virtual unsigned nIndices()=0;
	virtual unsigned nVertices()=0;
	virtual void write(IArray<VertexData> &vertices, IArray<int> &indices)=0;

	


};

