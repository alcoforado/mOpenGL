#ifndef IMATERIAL_H
#define IMATERIAL_H


template<class VerticeData>
class IMaterial
{
public:
    virtual void write(IArray<VerticeData> &array)=0;

};

#endif // IMATERIAL_H
