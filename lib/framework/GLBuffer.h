#ifndef GLBUFFER_H
#define GLBUFFER_H
#include <framework/ShapeBatch.h>
#include <GL.h>
#include <framework/VertexArrayAttribute.h>

template<class VerticeData>
class GLBuffer
{
private:
    struct AttributeInfo
    {
        VertexArrayAttribute Info;
        GLint ID;
    };

 public:
    enum AccessHint {DYNAMIC=GL_DYNAMIC_DRAW,STATIC=GL_STATIC_DRAW};

private:
    GL &_gl;
    AccessHint _accessHint;
    ShapeBatch<VerticeData>  _rootBatch;
    std::vector<VerticeData> _vertices;
    std::vector<Index>       _indices;
    GLuint  _glBufferV,_glBufferI;

    GLuint _glVertexArray;
    size_t _glSizeV,_glSizeI;
    std::vector<VertexArrayAttribute> _attribs;


    void bind()
    {
        assert(_gl.glIsVertexArray(_glVertexArray));
        _gl.glBindVertexArray(_glVertexArray);
        //_gl.glBindBuffer(GL_ARRAY_BUFFER,_glBufferV);
        //_gl.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_glBufferI);
    }

public:
    GLBuffer(GL &gl,const std::vector<VertexArrayAttribute> &attrs,AccessHint hint=DYNAMIC)
        :_gl(gl)
    {


        _accessHint = hint;
        _gl.glGenVertexArrays(1,&_glVertexArray);
        _gl.glBindVertexArray(_glVertexArray);
        _gl.glGenBuffers(1,&_glBufferV);
        _gl.glGenBuffers(1,&_glBufferI);
        _gl.glBindBuffer(GL_ARRAY_BUFFER,_glBufferV);
        _gl.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_glBufferI);
        _attribs=attrs;
        for (int i=0;i<_attribs.size();i++)
        {
            _gl.glVertexAttribPointer(i,
                                      _attribs[i].getComponentSize(),
                                      GL_FLOAT,
                                      false,
                                      sizeof(VerticeData),
                                      (GLvoid*) _attribs[i].getStructOffset());
            _gl.glEnableVertexAttribArray(i);
        }
        _glSizeV=_glSizeI=0;
    }



    void Allocate(size_t totalVertices,size_t totalIndices)
    {
        _vertices.resize(totalVertices);
        _indices.resize(totalIndices);

        _glSizeV=totalVertices;
        _glSizeI=totalIndices;

        this->bind();


        _gl.glBufferData(GL_ARRAY_BUFFER,
                         sizeof(VerticeData)*_vertices.size(),
                         nullptr,
                         _accessHint);

        _gl.glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                         sizeof(int)*_indices.size(),
                         nullptr,
                         _accessHint);

    }

    std::vector<ShapeBatch<VerticeData>>& GetRoot(){return _rootBatch;}

    void Sync()
    {
        if (_rootBatch.Changed())
        {
            auto nI = _rootBatch.nIndices();
            auto nV = _rootBatch.nVertices();
            _vertices.resize(nV);
            _indices.resize(nI);

            this->bind();

            this->_rootBatch.LazyRewrite(
                        &_vertices,
                         _vertices.size(),
                        &_indices,
                         _indices.size(),
                         false);


        }

    }

};


#endif // GLBUFFER_H
