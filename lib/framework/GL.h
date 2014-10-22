#ifndef ENGINEGL_H
#define ENGINEGL_H
#include <QOpenGLContext>
#include <QOpenGLFunctions_4_1_Core>
class GL : public QOpenGLFunctions_4_1_Core
{
    void setOpenGLContext(QOpenGLContext *context)
    {
      m_context=context;
      initializeOpenGLFunctions();
    }

  


  QOpenGLContext *m_context;
public:
  GL(QOpenGLContext *contex);

  QString getOpenGLInfo();

  enum GLBufferAccessHint {DYNAMIC=GL_DYNAMIC_DRAW,STATIC=GL_STATIC_DRAW};

    void testOpenGLCompatibility();


};

#endif // ENGINEGL_H
