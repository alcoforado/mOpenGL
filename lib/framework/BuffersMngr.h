#ifndef SHAPESMNGR_H
#define SHAPESMNGR_H
#include <framework/ShapeBatch.h>
#include <framework/GL.h>
#include <framework/GLBuffer.h>
#include <vector>
#include <framework/GLBuffer.h>
#include <shared/opointer.h>
template<class VerticeData>
class BuffersMngr
{
std::vector<OPointer<GLBuffer<VerticeData>>> _buffers;


public:
    GLBuffer<VerticeData>& operator[](int i)
    {
        assert(i<_buffers.size());
        return *_buffers[i];
    }
    void add_buffer(GL &gl,const std::vector<VertexArrayAttribute> &attrs,GL::AccessHint hint=GL::DYNAMIC)
    {
        auto buffer = new GLBuffer<VerticeData>(gl,attrs,hint);
        _buffers.push_back(OPointer(buffer));

    }








};

#endif // SHAPESMNGR_H
