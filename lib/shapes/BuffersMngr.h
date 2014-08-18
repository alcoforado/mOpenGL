#ifndef SHAPESMNGR_H
#define SHAPESMNGR_H
#include "ShapeBatch.h"
#include <GL.h>
#include <shaders/VertexArrayAttribute.h>
template<class VerticeData>
class BuffersMngr
{


    std::vector<Buffer> _buffers;
public:

    BuffersMngr(){}

    BuffersMngr(int nBuffers)
    {
        _buffers.resize(nBuffers);
    }

    //GetBatch(int bufferNumber,)




};

#endif // SHAPESMNGR_H
