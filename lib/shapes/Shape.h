#ifndef SHAPE_H
#define SHAPE_H

template<class VerticeData,class Topology, class Material>
class Shape : public IShape
{
    Topology _topology;
    Material _material;
    size_t _PosOff;
public:
    Shape(const Topology& topology,const Material& material)
    {
        _material=material;
        _topology=topology;

        VerticeData data;
        void *member = &(data.position);
        void *pData = &data;
        _PosOff = member-data;
    }


        
    virtual unsigned nIndices() {return _topology.nIndices();}
    virtual unsigned nVertices() {return _topology.nVetices();}
    virtual void  write(IArray<VertexData> &vertices, IArray<int> &indices)
    {


    }

    virtual ~Shape(){}



    
};

#endif // SHAPE_H
