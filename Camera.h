#pragma once

#include "Vector3.h"
#include "Matrix4x4.h"
#include <math.h>

#pragma managed(push,off)
class Camera
{
        Vector3 _focus;
        Vector3 _pos;
        Vector3 _up;
        Matrix4x4 proj; //The projection matrix
        Matrix4x4 world;
		Matrix4x4 worldproj; //The final view Matrix
        bool camChanged;

public:

		void UpdateData()
		{
			camChanged=false;
			world.LookAtRH(_pos, _focus, _up);
			worldproj.Multiply(world,proj);

		}


        Matrix4x4 getWorldProjMatrix()
        {
                if (camChanged)
                     UpdateData();
              	return worldproj;
        }

        Matrix4x4 getWorldMatrix()
        {
            if (camChanged)
	               UpdateData();
			return world;

        }
        const Matrix4x4  getProjectionMatrix()
        {
			if (camChanged)
				UpdateData();
            return proj;
        }

        void setLens(int X,int Y)
        {
            proj.PerspectiveForRH((float)M_PI / 4.0f, (float) X / (float) Y, 0.1f, 100.0f);
            camChanged = true;
        }


    };

#pragma managed(pop)


