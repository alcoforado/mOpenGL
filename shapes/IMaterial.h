#ifndef IMATERIAL_H
#define IMATERIAL_H


template<class Shader>
class IMaterial
{
public:
    virtual void write(IArray<Shader::VerticeData> &array)=0;

};

#endif // IMATERIAL_H
