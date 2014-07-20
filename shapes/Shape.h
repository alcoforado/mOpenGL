#ifndef SHAPE_H
#define SHAPE_H

template<class VerticeData,class Topology, class Material>
class Shape : public IShape
{
    Topology _topology;
    Material _material;
public:
    Shape(const Topology& topology,const Material& material)
    {
        _material=material;
        _topology=topology;
    }
        
    virtual unsigned nIndices() {return _topologin.nIndices();}
    virtual unsigned nVertices() {return _topologin.nIndices();}
    virtual void  write(IArray<VertexData> &vertices, IArray<int> &indices);
    virtual ~Shape(){}



    
};

#endif // SHAPE_H
