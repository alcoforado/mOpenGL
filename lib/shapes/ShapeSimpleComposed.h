#ifndef SHAPECOMPOSED_H
#define SHAPECOMPOSED_H

#include<shapes/IShape.h>
#include <utilities/RefArray.h>
#include <shapes/IShapeDynamic.h>
#include<vector>
/**
 * A shape composed by other shapes
 * This is used mainly for static shapes (shapes that doesn't change topology in time)
 * Advantage, is simple.
 *
 */

template<class VerticeData>
class ShapeSimpleComposed : public IShapeDynamic<VerticeData>
{


    std::vector<IShape<VerticeData>* > _v;
    bool _bNeedFlush;
private:
    void Changed()
    {
        TriggerChangeEvent();
        _bNeedFlush=true;

    }

public:
    ShapeSimpleComposed()
    {}





    virtual void write(IArray<VertexData> &vertices, IArray<int> &indices)
    {
        unsigned nVerts = nVertices();
        unsigned nIndices = nIndices();


        assert(nVerts <= vertices.size() );
        assert(nIndices <= indices.size());

       unsigned _offV=0;
       unsigned _offI=0;
       for(IShape<VerticeData>* shape : _v)
        {
           Index lV = shape->nVertices();
           Index lI = shape->nIndices();
           RefArray<VerticeData> vV(vertices,_offV,lV);
           RefArray<VerticeData> vI(indices,_offI,lI);
           shape->write(vV,vI);

           //Correct the indices
           for(int i=0;i<vI.size();i++)
            indices[i]+=_offI;

           _offV+=lV;
           _offI+=lI;

        }
    }

    virtual unsigned nIndices()
    {
        unsigned acum=0;
        for(IShape<VerticeData>* shape : _v)
        {
            acum+=shape->nIndices();
        }
        return acum;

    }

    virtual unsigned nVertices()
    {
        unsigned acum=0;
        for(IShape<VerticeData>* shape : _v)
        {
            acum+=shape->nVertices();
        }
        return acum;
   }


   bool NeedFlush()
   {
    return _bNeedFlush;
   }


    void AddShape(IShape<VerticeData> *shape)
    {
        _v.append(shape);
        Changed();
    }

    void RemoveShape(IShape<VerticeData> *shape)
    {
        bool exists=false;
        //find the shape and delete it.
        for(auto it=_v.begin();it!=_v.end();it++)
        {
            if (*it == shape){
                _v.erase(shape);
                exists=true;
            }
        }
        if (exists)
            Changed();
        else
            throw new Exception("Trying to delete a shape that do not exist");
    }

    virtual ~ShapeSimpleComposed()
    {
        for(auto ptr : _v)
        {
            delete ptr;
        }

    }


};

#endif // SHAPECOMPOSED_H
