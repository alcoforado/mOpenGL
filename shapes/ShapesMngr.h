#ifndef SHAPESMNGR_H
#define SHAPESMNGR_H
#include "ShapeBatch.h"

template<class VerticeData>
class BuffersMngr
{
    class Buffer
    {
        std::vector<ShapeBatch<VerticeData> > Batch;
        std::vector<VerticeData> _vertices;
        std::vector<Index>       _indices;
    };

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
