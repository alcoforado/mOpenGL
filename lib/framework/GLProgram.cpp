#include "GLProgram.h"
#include <Exception.h>
GLProgram::GLProgram(GL &gl,std::string VertexShaderText,std::string FragShaderText)
    :_gl(gl)
{
    _vertexShader =this->CreateShader(VertexShaderText, VERTEX_SHADER);
    _fragmentShader =this->CreateShader(FragShaderText, FRAGMENT_SHADER);

    //Create the program
    _program = _gl.glCreateProgram();
    _gl.glAttachShader(_program,_vertexShader);
    _gl.glAttachShader(_program,_fragmentShader);
    _gl.glLinkProgram(_program);

    //Check for link errors
    GLint linked;
    _gl.glGetProgramiv(_program,GL_LINK_STATUS,&linked);

    if (linked == GL_FALSE)
    {
        GLint logSize;
        _gl.glGetProgramiv(_program,GL_INFO_LOG_LENGTH,&logSize);
        if (logSize == 0)
            throw new Exception("Program Link failed for unknown reason");
        else
        {
            std::vector<char> log(logSize);
            _gl.glGetShaderInfoLog(_vertexShader,logSize,&logSize,&log[0]);
            std::string str = (&log[0]);
            throw new Exception("Program Link errors occured, Log:\n%s",str.c_str());
        }
    }





}



void GLProgram::AddVertexShader(std::string VerticeShaderText)
{
    _vertexShader =this->CreateShader(VerticeShaderText, VERTEX_SHADER);
}

void GLProgram::AddFragmentShader(std::string FragShaderText)
{
    _fragmentShader =this->CreateShader(FragShaderText, FRAGMENT_SHADER);
}

const std::vector<VertexArrayAttribute> &GLProgram::GetVertexArrayAttributes() const
{
    return _attrs;
}


GLint GLProgram::CreateShader(std::string VerticeShaderText, ShaderType shaderType)
{
    GLint shader;
    GLint compileStatus;
    const char *source = VerticeShaderText.c_str();

    shader=_gl.glCreateShader(shaderType);
    _gl.glShaderSource(shader,1,&source,NULL);
    _gl.glGetShaderiv(shader,GL_COMPILE_STATUS,&compileStatus);
    if (compileStatus == GL_FALSE) //Compilation Failed, throw exception with error
    {
        GLint logSize;
        _gl.glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&logSize);
        if (logSize == 0)
            throw new Exception("Compilation Failed for unknown reason");
        else
        {
            std::vector<char> log(logSize);
            _gl.glGetShaderInfoLog(_vertexShader,logSize,&logSize,&log[0]);
            std::string str = (&log[0]);
            throw new Exception("Compilation errors occured, Log:\n%s",str.c_str());
        }

    }
    return shader;
}

void GLProgram::SetVertexArrayAttributes(const std::vector<VertexArrayAttribute> &attrs)
{
    _attrs=attrs;
    GLuint i=0;
    for (VertexArrayAttribute attr : attrs)
    {
        _gl.glBindAttribLocation(_program,i++,attr.getName().c_str());
    }

}
