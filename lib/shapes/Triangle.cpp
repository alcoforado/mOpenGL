
#include "Triangle.h"




Triangle::Triangle(Vector3 &pt1, Vector3 &pt2, Vector3 &pt3)
{
    _data[0]=pt1;
    _data[1]=pt2;
    _data[2]=pt3;

}

Triangle::~Triangle(void)
{
}

void Triangle::WriteTopology(BufferSelect<Vector4> &vertices, IArray<Index> &indices)
{
    indices[0]=0;
    indices[1]=1;
    indices[2]=2;


    vertices[0]=glm::vec4(_data[0],1);
    vertices[1]=glm::vec4(_data[1],1);
    vertices[2]=glm::vec4(_data[2],1);


}
