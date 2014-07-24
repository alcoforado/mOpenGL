#ifndef ISHAPEWATCHER_H
#define ISHAPEWATCHER_H

#include <shapes/IShape.h>

template<class VertexData>
class IShapeWatcher
{
public:
    virtual void ShapeChanged(IShape<VertexData> *shape)=0;
    virtual void ShapeDeleted(IShape<VertexData> *shape)=0;


};

#endif // ISHAPEWATCHER_H
