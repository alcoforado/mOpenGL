#pragma once
#include <Vector4.h>
#include <Vector3.h>
#include <shapes/ITopology.h>
class Rectangle3D : public ITopology
{
	Vector3 _p0,_p1;
public:
	Rectangle3D(Vector3 &p1,Vector3 p2)
		:_p0(p1),_p1(p2)
	{

	}

	
	virtual unsigned nIndices(){ return 12;}
	virtual unsigned nVertices(){return 8;}
    virtual void WriteTopology(BufferSelect<Vector4> &vV,IArray<Index> &vI)
	{
		     vV[0] = Vector4(_p0[0], _p0[1], _p0[2],1);
             vV[1] = Vector4(_p0[0], _p1[1], _p0[2],1);
             vV[2] = Vector4(_p1[0], _p1[1], _p0[2],1);
             vV[3] = Vector4(_p1[0], _p0[1], _p0[2],1);
             vV[4] = Vector4(_p0[0], _p0[1], _p1[2],1);
             vV[5] = Vector4(_p0[0], _p1[1], _p1[2],1);
             vV[6] = Vector4(_p1[0], _p1[1], _p1[2],1);
             vV[7] = Vector4(_p1[0], _p0[1], _p1[2],1);

            int i = 0;
            //front Face
            vI[i++] = 0;vI[i++] = 1;vI[i++] = 2;
            vI[i++] = 0;vI[i++] = 2;vI[i++] = 3;

            //back Face
            vI[i++] = 4;  vI[i++] = 6;  vI[i++] = 5;
            vI[i++] = 4; vI[i++] = 7; vI[i++] = 6;

            //Left Face
            vI[i++] = 4; vI[i++] = 5; vI[i++] = 1;
            vI[i++] = 4; vI[i++] = 1; vI[i++] = 0;

            //Right Face
            vI[i++] = 3; vI[i++] = 2; vI[i++] = 6;
            vI[i++] = 3; vI[i++] = 6; vI[i++] = 7;

            //top Face
            vI[i++] = 1; vI[i++] = 5; vI[i++] = 6;
            vI[i++] = 1; vI[i++] = 6; vI[i++] = 2;

            //bottom Face
            vI[i++] = 4; vI[i++] = 0; vI[i++] = 3;
            vI[i++] = 4; vI[i++] = 3; vI[i++] = 7;

	}


};

