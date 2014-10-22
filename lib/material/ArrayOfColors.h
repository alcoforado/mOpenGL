#ifndef ARRAYOFCOLORS_H
#define ARRAYOFCOLORS_H
#include <framework/IMaterial.h>
#include <framework/Vector4.h>
#include <utilities/IArray.h>
#include <vector>
template<class VerticeData>
class ArrayOfColors : IMaterial<VerticeData>
{
    std::vector<Vector4> _colors;
public:
    ArrayOfColors(const Vector4 &v)
    {
        _colors.push_back(v);


    }
    virtual void write(IArray<VerticeData> &array) override
    {
        assert(!_colors.empty());
        int k=0;
        for (int i=0;i<array.size();i++)
        {
            if (k >= _colors.size())
                k=0;
            array[i].Color=_colors[k++];
        }

    }
};

#endif // ARRAYOFCOLORS_H
