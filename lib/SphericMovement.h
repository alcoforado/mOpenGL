#ifndef SPHERICMOVEMENT_H
#define SPHERICMOVEMENT_H
#include "Camera.h"

class SphericMovement
{

    Camera *_cam;
    float _alpha,_theta,_r;

public:
    SphericMovement(Camera *cam)
    {
        _cam = cam;
    }


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



    };



#endif // SPHERICMOVEMENT_H
