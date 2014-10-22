#ifndef ITOPOLOGY2D_H
#define ITOPOLOGY2D_H
#include <utilities/IArray.h>

#include <globals.h>
#include <utilities/EngineException.h>
#include <framework/IShape.h>
#include <framework/ArraySelect.h>
#include <framework/Vector2.h>


class ITopology2D
{
public:

   virtual TopologyType GetTopologyType()=0;
   virtual void WriteTopology(ArraySelect<Vector2> &vertices,IArray<Index> &indices)=0;
   virtual Index nVertices()=0;
   virtual Index nIndices()=0;

};


#endif // ITOPOLOGY2D_H
