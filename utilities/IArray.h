#include <globals.h>
#include <stddef.h>
#ifndef IARRAY_H
#define IARRAY_H
#include<assert.h>
template <class OfType>
class IArray
{

protected:
    IArray(){_ptr=NULL;_size=0;}
    OfType *_ptr;
    Index _size;
public:

    OfType& operator[](Index i)
    {
        assert(i<_size);
        return _ptr[i];
    }
    Index size() {return _size;}
};

#endif // IARRAY_H
