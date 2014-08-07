#ifndef REFARRAY_H
#define REFARRAY_H
#include <assert.h>
#include <utilities/IArray.h>
#include <vector>
template<class OfType>
class RefArray : public IArray<OfType>
{
    Index _off;
public:
    RefArray(IArray<OfType> &array, Index off, Index size)
    {
        assert( (off + size) <= array.size() );
        _off=off;
        this->_ptr=array.GetPointer()+_off;
        this->_size=size;
    }

    RefArray(std::vector<OfType> &array, Index off, Index size)
    {
        assert( (off + size) <= array.size() );
        _off=off;
        if (array.empty())
        {
            this->_size=0;
            this->_ptr=NULL;
        }
        else
        {
            this->_ptr=(&(array[0]))+_off;
            this->_size=size;
        }
    }


};

#endif // REFARRAY_H


