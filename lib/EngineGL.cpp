#include "EngineGL.h"
#include <QStringList>

EngineGL::EngineGL()
{

}


 QString EngineGL::getOpenGLInfo()
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
