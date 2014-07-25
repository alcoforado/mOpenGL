#ifndef SHAPECOMPOSED_H
#define SHAPECOMPOSED_H
#include <shapes/IShapeDynamic.h>
template<class VerticeData>
class ShapeDynamicComposed  : public IShapeDynamic<VerticeData>
{

    bool _bNeedFlush;
private:




    struct ShapeAllocInfo : IShapeWatcher<VerticeData>
    {
        ShapeDynamicComposed<VerticeData> *_collection;
        bool _changed;
        bool _markedForRemoval;
        IShapeDynamic<VerticeData> *_shape;
        int _currNIndices;
        int _currNVertices;
        int _index;

        virtual void ShapeChanged(IShape<VerticeData> *shape)
        {
            _changed=true;

            _nTotalIndices-=_currNIndices;
            _nTotalVertices-=_currNVertices;
            _currNIndices =shape->nIndices();
            _currNVertices=shape->nVertices();
            _nTotalIndices +=_currNIndices;
            _nTotalVertices+=_currNVertices;

        }
        virtual void ShapeDeleted(IShape<VerticeData> *shape)
        {
            _collection->RemoveShape(&shape);
        }
    };


    std::list<ShapeAllocInfo> _v;

    typename std::list<ShapeAllocInfo>::iterator findShape(IShapeDynamic<VerticeData> &shape)
    {
        for (auto it = _v.begin();it!=_v.end();it++)
        {
            if (it->shape == &shape)
                return it;
        }
        return _v.end();

    }

     Index computeNIndices()
     {
         Index acum=0;
         for (ShapeAllocInfo &info : _v)
         {
             acum+=info._shape->nIndices();
         }
         return acum;
     }


     Index computeNVertices()
     {
         Index acum=0;
         for (ShapeAllocInfo &info : _v)
         {
             acum+=info._shape->nVertices();
         }
         return acum;
     }


     Index _nTotalIndices, _nTotalVertices;



public:

    ShapeDynamicComposed(){}
    virtual ~ShapeDynamicComposed(){}

    void AddShape(IShapeDynamic<VerticeData> &shape)
    {
        //create a  ShapeInfo entry in the list
        _v.push_back(ShapeAllocInfo());

        //Set the entry
        ShapeAllocInfo &info = _v.back();
        info._index = _v.size();
        info._currNIndices = shape->NIndices();
        info._currNVertices = shape->NVertices();
        info._changed=true;
        info._markedForRemoval=false;
        info._shape = &shape;
        info._shape->AddWatcher(this);

        _nTotalIndices +=info._currNIndices;
        _nTotalVertices+=info._currNVertices;

    }

    void RemoveShape(IShapeDynamic<VerticeData> &shape)
    {
        //find the shape and flag it for removal
        auto it  = this->findShape(shape);
        assert(it!=_v.end());
        if (it != _v.end())
        {
            _nTotalVertices-=it->_currNVertices;
            _nTotalIndices-=it->_currNIndices;
            _v.erase(it);
        }
    }

    virtual void write(IArray<VerticeData> &vertices, IArray<int> &indices)
    {

    }


    virtual unsigned nIndices(){
        assert(_nTotalIndices == computeNIndices());
        return _nTotalIndices;
    }

    virtual unsigned nVertices() {
        assert(_nTotalVertices == computeNVertices());
        return _nTotalVertices;
    }

};

#endif // SHAPECOMPOSED_H
