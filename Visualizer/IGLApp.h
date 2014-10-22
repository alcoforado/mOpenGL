#ifndef IGLAPP_H
#define IGLAPP_H
#include <framework/GL.h>
#include <shaders/ColorShader2D.h>
#include <shared/opointer.h>
class IGLApp
{
private:
    GL *pEngine;
    OPointer<ColorShader2D> pShader;
public:
    GL& getGL(){return *pEngine;}
    IGLApp(GL &gl);
    virtual void draw()=0;
    virtual void initialize()=0;

};

#endif // IGLAPP_H
