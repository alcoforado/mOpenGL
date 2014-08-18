#ifndef GLPROGRAM_H
#define GLPROGRAM_H
#include <string>
#include <qopenglfunctions_4_1_core.h>
#include <GL.h>
#include <framework/VertexArrayAttribute.h>
#include <vector>
class GLProgram
{
private:
    GL &_gl;
    GLint _vertexShader;
    GLint _fragmentShader;
    GLint _program;
    std::vector<VertexArrayAttribute> _attrs;


public:
    enum ShaderType{VERTEX_SHADER=GL_VERTEX_SHADER,FRAGMENT_SHADER=GL_FRAGMENT_SHADER};

private:
    GLint CreateShader     (std::string VerticeShaderText,ShaderType shaderType);
    void SetVertexArrayAttributes(const std::vector<VertexArrayAttribute> &attrs);
    void AddVertexShader  (std::string VerticeShaderText);
    void AddFragmentShader(std::string FragShaderText);
    const std::vector<VertexArrayAttribute>& GetVertexArrayAttributes() const;



public:

    GLProgram(GL &gl,std::string VertexShaderText,std::string FragShaderText);

    ~GLProgram(){}


};

#endif // GLPROGRAM_H
