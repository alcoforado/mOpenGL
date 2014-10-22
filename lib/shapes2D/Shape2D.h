#ifndef SHAPE2D_H
#define SHAPE2D_H
#include <type_traits>
#include <ITopology2D.h>
#include <framework/IShape.h>
#include <framework/IMaterial.h>
#include <framework/Vector2.h>
template<class VerticeData,
         class Topology2D,
         class Material>
class Shape2D : IShape<Shader::VerticeData>
{
private:
    Topology2D &_topology;
    Material   &_material;
public:
    Shape2D(Shader &shader,Topology2D &tp2D,Material &mat)
        :_topology(tp2D),_material(mat),_shader(shader)
    {


    }

    Topology2D& GetTopology(){return _topology;}
    Material& GetMaterial(){return _material;}


    virtual TopologyType GetTopologyType() final
    {
        return _topology.GetTopologyType();
    }

    virtual unsigned nIndices() final
    {
        return _topology.nIndices();
    }

    virtual unsigned nVertices() final
    {
        return _topology.nVertices();
    }

    virtual void write(IArray<VerticeData> &vertices, IArray<int> &indices)
    {

    }

    virtual bool IsIndexed() final {return nIndices() == 0;}
};

#endif // SHAPE2D_H
