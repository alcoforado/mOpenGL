#ifndef VERTICEARRAY_H
#define VERTICEARRAY_H


#include <vector>
#include <framework/Vector4.h>
#include <utilities/IArray.h>
template<class MemberType>
class ArraySelect
{
    float *_data;
    int _size;
    int _type_off;
    int _member_off;


public:
    template<class ClassType>
    ArraySelect(std::vector<ClassType> &data, MemberType ClassType::*vertice)
    {
        static_assert(sizeof(ClassType)%4 == 0,"Type cannot have 4 bytes alignment");
        _data = (float*) &(data[0]);
        _size = data.size();
        _type_off=sizeof(ClassType)/sizeof(float);
        _member_off=  ((float*)&(data[0].*vertice)) - ((float*) &(data[0])) ;
    }

    template<class ClassType>
    ArraySelect(IArray<ClassType> &data, MemberType ClassType::*vertice)
    {
        static_assert(sizeof(ClassType)%4 == 0,"Type cannot have 4 bytes alignment");
        _data = (float*) &(data[0]);
        _size = data.size();
        _type_off=sizeof(ClassType)/sizeof(float);
        _member_off=  ((float*)&(data[0].*vertice)) - ((float*) &(data[0])) ;
    }


    int size() {return _size;}

    MemberType& operator[](int i) {
        assert(i<_size);
        return *((MemberType*) (_data + (i*_type_off + _member_off)));
    }

};



#endif // VERTICEARRAY_H
