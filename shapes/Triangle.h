#pragma once

#include <glm/glm.hpp>
#include <shapes/ITopology.h>
#include <shapes/Vector3.h>
class Triangle : ITopology
{
    Vector3 _data[3];
public:
    Triangle(Vector3 &pt1,Vector3 &pt2,Vector3 &pt3);
	virtual ~Triangle(void);
    virtual unsigned nIndices(){return 3;}
	virtual unsigned nVertices(){return 3;}
    void WriteTopology(BufferSelect<Vector4> &vertices,IArray<Index> &indices);


};

