#include "GL.h"
#include <QStringList>
#include <assert.h>
GL::GL(QOpenGLContext *contex)
{
    this->setOpenGLContext(contex);
    this->testOpenGLCompatibility();
}


 QString GL::getOpenGLInfo()
 {
    GLint nE=0;

   QString strVersion=(char*) glGetString(GL_VERSION);
   QString strVendor=(char*)glGetString(GL_VENDOR);
   QString strRender=(char*)glGetString(GL_RENDER);
   QString strShadingLanguage=(char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
   QString ext="";//(char*) glGetString(GL_EXTENSIONS);
   glGetIntegerv(GL_NUM_EXTENSIONS,&nE);
   for (int i=0;i<nE;i++)
     {
       ext+="\t";
       ext+= (char*) glGetStringi(GL_EXTENSIONS,i);
       ext+="\n";


     }
   return QString("OpenGL Info:\nVersion: %1\nVendor:           %2\nRender:           %3\nShading Language: %4\nExtensions:\n%5").arg(strVersion,strVendor,strRender,strShadingLanguage,ext);







 }

 void GL::testOpenGLCompatibility()
 {
     GLboolean b;
     this->glGetBooleanv(GL_SHADER_COMPILER,&b);
     assert(b == GL_TRUE);
     assert(sizeof(char) == sizeof(GLchar));

 }
