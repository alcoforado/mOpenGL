#pragma once
#include "Stdafx.h"
#include "Vector3.h"
#include "Matrix4x4.h"
#include <math.h>

#pragma managed(push,off)
class Camera
{
        Vector3 _focus;
        Vector3 _pos;
        Vector3 _up;
        double _r, _alpha, _theta;
        Matrix4x4 proj; //The projection matrix
        Matrix4x4 world;
		Matrix4x4 worldproj; //The final view Matrix
        bool camChanged;

public:
        float getR() { return (float) _r; }
        double getAlpha() { return _alpha; }
        double getTheta() { return _theta; }

        void setCamera(double r, double theta, double alfa)
        {
            _alpha = alfa;
            _theta = theta;
            _r = r;
            
            double sin_alpha=sin(alfa);
            double cos_alpha=cos(alfa);
            double sin_theta=sin(theta);
            double cos_theta=cos(theta);
            double cos_alpha_90 = sin_alpha;
            double sin_alpha_90 = -cos_alpha;

            _pos.X=(float)(r * cos_theta * sin_alpha);
            _pos.Y=(float)(r * sin_theta * sin_alpha);
            _pos.Z=(float)(r * cos_alpha);

            _up.X = (float)(r * cos_theta * sin_alpha_90);
            _up.Y = (float)(r * sin_theta * sin_alpha_90);
            _up.Z = (float)(r * cos_alpha_90);

            //DXApp.log.WriteLine("{0} {1}", _pos, _up);
           
            camChanged = true;
        }

        void moveSpheric(float d_theta, float d_alpha)
        {
            _alpha += d_alpha;
            _theta += d_theta;

            setCamera(_r, _theta, _alpha);

        }

        void moveRadius(float dr)
        {
            _r += dr;
            if (_r < 0)
                _r = 0;
            setCamera(_r, _theta, _alpha);
        }

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

        bool CamChanged()
        {
            return camChanged;

        }
    };

#pragma managed(pop)


