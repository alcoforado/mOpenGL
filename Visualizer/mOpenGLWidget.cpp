#include "mOpenGLWidget.h"
#include <QOpenGLContext>
#include <iostream>

mOpenGLWidget::mOpenGLWidget(QWidget *parent)
    :QGLWidget(parent)
{
    m_context=NULL;


}




mOpenGLWidget::~mOpenGLWidget()
{

    return;
}


void mOpenGLWidget::initializeGL()
{
    glClearColor(0.0, 1.0, 0.0, 0.0);
    m_context = this->context();
    QOpenGLContext *new_context= m_context->contextHandle();

    pEngine = new GL(new_context);
    pShader = new ColorShader2D(*pEngine);

}

void mOpenGLWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT);

    m_context->swapBuffers();

}


void mOpenGLWidget::resize(int w, int h)
{

    glViewport(0,0,w,h);


}

