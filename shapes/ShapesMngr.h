#ifndef SHAPESMNGR_H
#define SHAPESMNGR_H
#include "ShapeBatch.h"

template<class VerticeData>
class BuffersMngr
{
    struct Buffer
    {
        std::vector<ShapeBatch<VerticeData> > _batches;
       // std::vector<

    };


public:



    BuffersMngr();

};

#endif // SHAPESMNGR_H
