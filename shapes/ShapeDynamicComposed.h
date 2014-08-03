#ifndef SHAPECOMPOSED_H
#define SHAPECOMPOSED_H
#include <shapes/IShapeDynamic.h>
#include <utilities/RefArray.h>
template<class VerticeData>
class ShapeDynamicComposed  : public IShapeDynamic<VerticeData>
{


private:






    struct ShapeAllocInfo : IShapeWatcher<VerticeData>
    {
        ShapeDynamicComposed<VerticeData> *_collection;
        IShapeDynamic<VerticeData> *_shape;
        int _currNIndices;
        int _currNVertices;
        int _index;


        virtual void ShapeChanged(IShape<VerticeData> *shape)
        {

            _nTotalIndices-=_currNIndices;
            _nTotalVertices-=_currNVertices;
            _currNIndices =shape->nIndices();
            _currNVertices=shape->nVertices();
            _nTotalIndices +=_currNIndices;
            _nTotalVertices+=_currNVertices;
            _collection->TriggerChangedEvent();

        }
        virtual void ShapeDeleted(IShape<VerticeData> *shape)
        {
            _collection->RemoveShape(&shape);
            _collection->TriggerChangedEvent();
        }
    };


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
     std::list<ShapeAllocInfo> _v;
     TopologyType _type;

public:

    ShapeDynamicComposed(){}
    virtual ~ShapeDynamicComposed(){}


    virtual TopologyType GetTopologyType(){return _type;}

    void AddShape(IShapeDynamic<VerticeData> &shape)
    {
        if (_v.empty())
            _type=shape.GetTopologyType();
        assert(_type == shape.GetTopologytype());

        //create a  ShapeInfo entry in the list
        _v.push_back(ShapeAllocInfo());

        //Set the entry
        ShapeAllocInfo &info = _v.back();
        info._index = _v.size();
        info._currNIndices = shape->NIndices();
        info._currNVertices = shape->NVertices();
        info._shape = &shape;
        info._shape->AddWatcher(&info);

        _nTotalIndices +=info._currNIndices;
        _nTotalVertices+=info._currNVertices;
        this->TriggerChangeEvent();

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
            this->TriggerChangedEvent();
        }

    }

    virtual void Write(IArray<VerticeData> &vertices, IArray<int> &indices)
    {
        unsigned nVerts  = this->nVertices();
        unsigned nIndices= this->nIndices();


      assert(nVerts <= vertices.size() );
      assert(nIndices <= indices.size());

       unsigned _offV=0;
       unsigned _offI=0;
       for(ShapeAllocInfo& info : _v)
        {
           Index lV = info._shape->nVertices();
           Index lI = info->_shape->nIndices();
           RefArray<VerticeData> vV(vertices,_offV,lV);
           RefArray<Index> vI(indices,_offI,lI);
           info->_shape->write(vV,vI);

           //Correct the indices
           for(int i=0;i<vI.size();i++)
            indices[i]+=_offI;

           _offV+=lV;
           _offI+=lI;

        }
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
