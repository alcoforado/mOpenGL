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

        bool _changed;
        bool _markedForRemoval;
        IShapeDynamic<VerticeData> *_shape;
        int _currNIndices;
        int _currNVertices;
        int _index;

        virtual void ShapeChanged(IShape<VerticeData> *shape)
        {
            _changed=true;
        }
        virtual void ShapeDeleted(IShape<VerticeData> *shape)
        {
            _changed=true;
            _markedForRemoval=true;
            _shape=NULL;
        }
    };

    std::list<ShapeAllocInfo> _v;

    ShapeAllocInfo* findShape(IShapeDynamic<VerticeData> &shape)
    {
        for (auto el : _v)
        {
            if (el.shape == &shape)
                return &el;
        }
        return NULL;

    }

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
        info._currNIndices = 0;
        info._currNVertices = 0;
        info._changed=true;
        info._markedForRemoval=false;
        info._shape = &shape;
        info._shape->AddWatcher();

    }

    void RemoveShape(IShapeDynamic<VerticeData> &shape)
    {
        //find the shape and flag it for removal
        ShapeAllocInfo *info = this->findShape(shape);
        assert(info!=NULL);
        if (info != NULL)
        {
            info->_changed=true;
            info->_markedForRemoval=true;
        }
    }



};

#endif // SHAPECOMPOSED_H
