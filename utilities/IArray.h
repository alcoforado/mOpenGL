#include <globals.h>
#include <stddef.h>
#ifndef IARRAY_H
#define IARRAY_H
template <class OfType>
class IArray
{
    OfType *_ptr;
    Index _size;
protected:
    IArray(){_ptr=NULL;_size=0;}

public:

    OfType& operator[](Index i)
    {
        assert(i<_size);
        return _ptr[i];
    }
    Index size() {return _size;}
};

#endif // IARRAY_H
