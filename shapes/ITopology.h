#ifndef ITOPOLOGY_H
#define ITOPOLOGY_H

#include "BufferSelect.h"
#include "Vector4.h"
#include <utilities/IArray.h>
#include <globals.h>
#include <utilities/EngineException.h>
#include "IShape.h"
/**
 * @brief The ITopology class responsible to write the topology of the shape.
 *       Although this class defines its methods as virtual, they almost never
 *        are called as virtual functions. We use basically static typing with templates.
 */
class ITopology
{
public:
   ITopology();
   TopologyType GetTopologyType(){throw new EngineException("not Implemented");}
   void WriteTopology(BufferSelect<Vector4> &vertices,IArray<Index> &indices) {(void)indices;(void)vertices;throw new EngineException("not Implemented");}
   Index nVertices(){throw new EngineException("not Implemented");}
   Index nIndices(){throw new EngineException("not Implemented");}

};

#endif // ITOPOLOGY_H
