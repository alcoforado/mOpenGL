#ifndef ISHAPEWATCHER_H
#define ISHAPEWATCHER_H

template<class VertexData>
class IShape;

template<class VertexData>
class IShapeWatcher
{
public:
    virtual void ShapeChanged(IShape<VertexData> *shape)=0;
    virtual void ShapeDeleted(IShape<VertexData> *shape)=0;


};

#endif // ISHAPEWATCHER_H
