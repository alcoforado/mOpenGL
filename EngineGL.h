#ifndef ENGINEGL_H
#define ENGINEGL_H
#include <QOpenGLContext>
#include <QOpenGLFunctions_4_1_Core>
class EngineGL : QOpenGLFunctions_4_1_Core
{

  
  QOpenGLContext *m_context;
public:
  EngineGL();

  QString getOpenGLInfo();

  void setOpenGLContext(QOpenGLContext *context)
  {
    m_context=context;
    initializeOpenGLFunctions();

  }
};

#endif // ENGINEGL_H
