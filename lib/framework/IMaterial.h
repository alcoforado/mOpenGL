#ifndef IMATERIAL_H
#define IMATERIAL_H

#include <utilities/IArray.h>
template<class VerticeData>
class IMaterial
{
public:
    virtual void write(IArray<VerticeData> &array)=0;

};

#endif // IMATERIAL_H
