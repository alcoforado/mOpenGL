#ifndef ENGINEGL_H
#define ENGINEGL_H
#include <QOpenGLContext>
#include <QOpenGLFunctions_4_1_Core>
class GL : public QOpenGLFunctions_4_1_Core
{

  
  QOpenGLContext *m_context;
public:
  GL();

  QString getOpenGLInfo();

  void setOpenGLContext(QOpenGLContext *context)
  {
    m_context=context;
    initializeOpenGLFunctions();
  }

    void testOpenGLCompatibility();


};

#endif // ENGINEGL_H
