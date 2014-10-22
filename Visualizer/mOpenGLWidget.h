#ifndef MOPENGLWIDGET_H
#define MOPENGLWIDGET_H

#include <QtOpenGL/QGLWidget>

#include <QOpenGLContext>
#include <framework/GL.h>
#include <shaders/ColorShader2D.h>
#include <memory>
#include <shared/opointer.h>
class mOpenGLWidget : public QGLWidget
{    
    Q_OBJECT

    int a;
    OPointer<GL> pEngine;
    OPointer<ColorShader2D> pShader;
    QGLContext *m_context;
public:
    mOpenGLWidget(QWidget *parent);
    QOpenGLContext* GetQOpenGLContext(){return m_context->contextHandle();}
    virtual ~mOpenGLWidget();

protected:
   virtual void initializeGL();
   virtual void paintGL();
   virtual void resize(int w, int h);
};

#endif // MOPENGLWIDGET_H
