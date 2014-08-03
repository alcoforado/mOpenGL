#pragma once



#include <utilities/EngineException.h>
#include <utilities/IArray.h>


enum TopologyType {POINTS,TRIANGLES,LINES,MIXED,EMPTY};

template<class VertexData>
class IShape
{


public:
    virtual TopologyType GetTopologyType()=0;
	virtual unsigned nIndices()=0;
	virtual unsigned nVertices()=0;
    virtual void write(IArray<VertexData> &vertices, IArray<int> &indices, bool bFlush)=0;
    virtual bool IsIndexed() {return nIndices() == 0;}


};

