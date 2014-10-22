#ifndef ONERECT_H
#define ONERECT_H
#include "IGLApp.h"
#include <shaders/ColorShader2D.h>
class OneRect : public IGLApp
{
     OPointer<ColorShader2D> pShader;
public:
    using IGLApp::IGLApp;

    virtual void redraw();


    virtual void initialize();

};

#endif // ONERECT_H
