#ifndef ITOPOLOGY2D_H
#define ITOPOLOGY2D_H
#include "BufferSelect.h"
#include "Vector4.h"
#include <utilities/IArray.h>
#include <globals.h>
#include <utilities/EngineException.h>
#include "Vector2.h"
#include "IShape.h"


class ITopology2D
{
public:
    ITopology2D();

   TopologyType GetTopologyType(){throw new EngineException("not Implemented");}
   void WriteTopology(BufferSelect<Vector2> &vertices,IArray<Index> &indices) {(void)indices;(void)vertices;throw new EngineException("not Implemented");}
   Index nVertices() {throw new EngineException("not Implemented");}
   Index nIndices() {throw new EngineException("not Implemented");}

};


#endif // ITOPOLOGY2D_H
