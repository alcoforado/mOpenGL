#include "WindowGL.h"
#include <QOpenGLContext>
#include <QDebug>

WindowGL::WindowGL(QWindow *parent, QSurfaceFormat format)
  :QWindow(parent)
{
  Q_UNUSED(parent);
  this->setSurfaceType(QWindow::OpenGLSurface);
  this->setFormat(format);
  m_context = new QOpenGLContext(this);
  m_context->setFormat(requestedFormat());
  this->create();
  m_context->create();
  m_context->makeCurrent(this);
  engine.setOpenGLContext(m_context);

}

void WindowGL::render()
{

  if (isExposed())
    {
   qDebug() << engine.getOpenGLInfo();
  glClear(GL_COLOR_BUFFER_BIT);
  m_context->makeCurrent(this);
  glFlush();
  m_context->swapBuffers(this);

    }
 //Debug() << "Render Called \n";
}

void WindowGL::resizeEvent(QResizeEvent *event)
{
  Q_UNUSED(event);
  glViewport(0,0,width(),height());
 //qDebug() << "Resize Called \n"

}
void WindowGL::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);

    if (isExposed())
        render();
}


bool WindowGL::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::UpdateRequest:
        render();
        return true;
    default:
        return QWindow::event(event);
    }
}

