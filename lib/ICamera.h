#pragma once
#include "Camera.h"
ref class ICamera
{
	Camera *cam;
public:
	ICamera(Camera *cam)
		:cam(cam)
	{
		
	}

	    float getR() { return cam->getR(); }
        double getAlpha() { return cam->getAlpha(); }
        double getTheta() { return cam->getTheta(); }

        void setCamera(double r, double theta, double alfa)
        {
			cam->setCamera(r,theta,alfa);
        }

        void moveSpheric(float d_theta, float d_alpha)
        {
			cam->moveSpheric(d_theta,d_alpha);
        }

        void moveRadius(float dr)
        {
			cam->moveRadius(dr);
		}

	!ICamera()
	{
		delete cam;
	}
	~ICamera(){}
};

