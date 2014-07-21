#ifndef SHAPECOMPOSED_H
#define SHAPECOMPOSED_H

#include<shapes/IShape.h>
#include<vector>
/**
 * A shape composed by other shapes
 * This is used mainly for static shapes (shapes that doesn't change topology in time)
 * Advantage, is simple.
 */

template<class Shader>
class ShapeSimpleComposed : public IShape<Shader>
{
    std::vector<IShape<Shader>* > _v;

public:
    ShapeSimpleComposed();
    virtual ~ShapeSimpleComposed()
    {
        for(auto ptr : _v)
        {
            delete ptr;
        }
    }
};

#endif // SHAPECOMPOSED_H
