#ifndef RECT2D_H
#define RECT2D_H
#include <shapes2D/ITopology2D.h>
#include <framework/Vector2.h>
template<class VerticeData>
class Rect2D : public ITopology2D<VerticeData>
{
private:
    Vector2 _p1,_p2;

public:
    Rect2D(const Vector2 &p1, const Vector2 &p2)
        :_p1(p1),_p2(p2)
    {}

    virtual TopologyType GetTopologyType() override
    {
        return  TRIANGLES;
    }

    virtual void WriteTopology(IArray<VerticeData> &vertices,IArray<Index> &indices) override
    {
        vertices[0].Position=glm::vec2(_p1[0],_p1[1]);
        vertices[1].Position=glm::vec2(_p2[0],_p1[1]);
        vertices[2].Position=glm::vec2(_p2[0],_p2[1]);
        vertices[3].Position=glm::vec2(_p1[0],_p2[1]);

        indices[0]=0;
        indices[1]=1;
        indices[2]=2;
        indices[3]=0;
        indices[4]=2;
        indices[5]=3;

    }



    virtual Index nVertices() override {return 4;}
    virtual Index nIndices()  override {return 6;}


};

#endif // RECT2D_H
