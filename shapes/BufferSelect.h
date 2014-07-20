#ifndef BUFFERMEMBEREXTRACTOR_H
#define BUFFERMEMBEREXTRACTOR_H

#include <globals.h>
#include <vector>
#include <assert.h>
template <class MemberType>
class BufferSelect
{
  char  *_data;
  Index _arraySize;
  Index _structSize;
  const Index _offInStruct;



public:
  BufferSelect(char *array,Index arraySize,Index structSize,int field_offset_in_bytes)
  {
          _data=array;
          _offInStruct=field_offset_in_bytes;
          _arraySize=arraySize;
          _structSize=structSize;
  }

  template<class StructType>
  BufferSelect(StructType* array,Index arraySize,int field_offset_in_bytes)
  {
      _data = (char*) array;
      _arraySize = arraySize;
      _offInStruct=field_offset_in_bytes;
      _structSize = sizeof(StructType);

  }



  //Default property
MemberType& operator[](Index i)
{
  assert(i<_arraySize);
  return *( (MemberType*) (_data+ i*_structSize+_offInStruct));
}

  Index size(){return _arraySize;}

};

#endif // BUFFERMEMBEREXTRACTOR_H
