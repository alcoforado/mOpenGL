#ifndef REFARRAY_H
#define REFARRAY_H
#include <assert.h>
#include <utilities/IArray.h>
template<class OfType>
class RefArray : public IArray<OfType>
{
    Index _off;
public:
    RefArray(IArray<OfType> &array, Index off, Index size)
    {
        assert( (off + size) <= array.size() );
        _off=off;
        this->_ptr=array._ptr+_off;
        this->_size=size;
    }

};

#endif // REFARRAY_H


