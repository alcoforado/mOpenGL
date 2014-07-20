
#include "Triangle.h"


Triangle::Triangle(XMFLOAT3 pt1,XMFLOAT3 pt2,XMFLOAT3 pt3)
{
	_data[0]=pt1;
	_data[1]=pt2;
	_data[2]=pt3;
}


Triangle::~Triangle(void)
{
}
