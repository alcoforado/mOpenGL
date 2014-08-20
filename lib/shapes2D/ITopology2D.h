#ifndef ITOPOLOGY2D_H
#define ITOPOLOGY2D_H
#include <utilities/IArray.h>
#include <globals.h>
#include <utilities/EngineException.h>
#include <framework/IShape.h>

template<class VerticeData>
class ITopology2D
{
public:

   virtual TopologyType GetTopologyType()=0;
   virtual void WriteTopology(IArray<VerticeData> &vertices,IArray<Index> &indices)=0;
   virtual Index nVertices()=0;
   virtual Index nIndices()=0;

};


#endif // ITOPOLOGY2D_H
