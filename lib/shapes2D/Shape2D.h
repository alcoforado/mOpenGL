#ifndef SHAPE2D_H
#define SHAPE2D_H
#include <type_traits>
#include <ITopology2D.h>
#include <framework/IShape.h>
#include <framework/IMaterial.h>
#include <framework/Vector2.h>
template<class VerticeData,
         class Topology2D=ITopology2D<VerticeData>,
         class Material=IMaterial<VerticeData>>
class Shape2D : IShape<VerticeData>
{
private:
    Topology2D &_topology;
    Material   &_material;

public:
    Shape2D(Topology2D &tp2D,Material &mat)
        :_topology(tp2D),_material(mat)
    {

        //Vertify if VerticeData contain a member Position with type Vector2
        static_assert(std::is_same<decltype(VerticeData::Position),Vector2>::value,
                      "Expect VerticeData to have a member called Position of type Vector2");

    }


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

    virtual void write(IArray<VerticeData> &vertices, IArray<int> &indices) final
    {
        _topology.WriteTopology(vertices,indices);
        _material.write(vertices);
    }

    virtual bool IsIndexed() final {return nIndices() == 0;}




};

#endif // SHAPE2D_H
