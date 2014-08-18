#ifndef SHAPEROOT_H
#define SHAPEROOT_H

#include <framework/IShape.h>
#include <utilities/RefArray.h>
#include <vector>
#include <framework/ShapeBatch.h>
/** A shape root is a shape batch that is the lonly owner of a Buffer of primitives
 *
 */
template<class VerticeData>
class ShapeRoot
{
    ShapeBatch<VerticeData> _batch;

    bool _bNeedFlush;
    std::vector<VerticeData> _vertices;
    std::vector<Index> _indices;


private:


    enum ShapeStatus { Updated,Changed,JustAdded,ToBeRemoved,Expanded,Contracted,WriteOnly};

    struct ShapeAllocInfo : IShapeWatcher<VerticeData>
    {
        ShapeRoot<VerticeData> *_root;

        int _currNIndices;
        int _currNVertices;
        int _offI;
        int _offV;
        ShapeStatus _status;

        virtual void ShapeChanged(IShape<VerticeData> *shape)
        {
            _status=Changed;
            _root->_bNeedFlush=true;

        }
        virtual void ShapeDeleted(IShape<VerticeData> *shape)
        {
            _root->RemoveShape(shape);
        }

        bool Changed()
        {
            return _status != Updated;

        }
    };


    std::list<ShapeAllocInfo> _v;

    typename std::list<ShapeAllocInfo>::iterator findShape(IShape<VerticeData> *shape)
    {
        for (auto it = _v.begin();it!=_v.end();it++)
        {
            if (it->shape == shape)
                return it;
        }
        return _v.end();

    }

     Index computeNIndices()
     {
         Index acum=0;
         for (ShapeAllocInfo &info : _v)
         {
             if (info._state == ToBeRemoved)
                 continue;
             if (info.Changed())
                 acum+=info._shape->nIndices();
             else
                acum+=info._currNIndices;
         }
         return acum;
     }


     Index computeNVertices()
     {
         Index acum=0;
         for (ShapeAllocInfo &info : _v)
         {
             if (info._state == ToBeRemoved)
                 continue;
             if (info.Changed())
                 acum+=info._shape->nVertices();
             else
                acum+=info._currNVertices;
         }
         return acum;
     }





public:

    ShapeRoot(){}
    virtual ~ShapeRoot(){}

    void AddShape(IShape<VerticeData> &shape)
    {
        _batch.AddShape(shape);
    }

    void RemoveShape(IShape<VerticeData> *shape)
    {
        _batch.RemoveShape(shape);
    }

    virtual void Flush(bool bForceFlush)
    {
        _vertices.resize(_batch.nVertices());
        _indices.resize(_batch.nIndices());
        _batch.ReWriteAll(&_vertices,
                          0,
                          _vertices.size(),
                          &_indices,
                          _indices.size()
                          );

    }





    virtual unsigned nIndices(){
       return  _batch.nIndices();
    }

    virtual unsigned nVertices() {
       return _batch.nVertices();

    }

};





#endif // SHAPEROOT_H
