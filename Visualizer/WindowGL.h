#ifndef WINDOWGL_H
#define WINDOWGL_H

#include <QWindow>
#include <framework/GL.h>
#include <shaders/ColorShader2D.h>
#include <shared/opointer.h>
#include <memory>
class WindowGL : public QWindow
{
  Q_OBJECT
    std::unique_ptr<GL> pEngine;


    std::unique_ptr<ColorShader2D> pShader;

public:
  WindowGL(QWindow *parent,QSurfaceFormat format);
  ~WindowGL(){}
  virtual void render();
  GL& GetOpenGLContext(){return *pEngine;}

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
