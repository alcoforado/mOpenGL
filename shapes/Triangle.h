#pragma once
#include "AbstractShape.h"


using DirectX::XMFLOAT3;
class Triangle :
	public AbstractShape
{
	XMFLOAT3 _data[3];
public:
	Triangle(XMFLOAT3 pt1,XMFLOAT3 pt2,XMFLOAT3 pt3);
	virtual ~Triangle(void);
	virtual unsigned nTriangles(){return 1;}
	virtual unsigned nVertices(){return 3;}
	/*virtual void write(ShapesMngr::Indices &indices, ShapesMngr::Vertices &vertices)
	{
		vertices[0]=_data[0];
		vertices[1]=_data[1];
		vertices[2]=_data[2];

		indices[0]=0;
		indices[1]=1;
		indices[2]=2;
	}*/
};

