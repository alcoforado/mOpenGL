#ifndef WINDOWGL_H
#define WINDOWGL_H

#include <QWindow>
#include <GL.h>
#include <shaders/ColorShader2D.h>

class WindowGL : public QWindow
{
  Q_OBJECT



    OPointer<ColorShader2D> *op;

public:
  WindowGL(QWindow *parent,QSurfaceFormat format);
  ~WindowGL(){}
  virtual void render();
  GL engine;
 public slots:


 protected:
//     bool event(QEvent *event);

  //   void exposeEvent(QExposeEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void exposeEvent(QExposeEvent *event);

    virtual bool event(QEvent *event);

private:
    // bool m_update_pending;
    // bool m_animating;

     QOpenGLContext *m_context;

 };




#endif // WINDOWGL_H
