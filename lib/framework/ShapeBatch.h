#ifndef SHAPEBATCH_H
#define SHAPEBATCH_H


#include <shapes/IShapeDynamic.h>
#include <utilities/RefArray.h>
#include <utilities/EngineException.h>
#include <vector>


/** A shape root is responsible for the serialization of the shapes
 * It is designed to uniquely be  associated with one buffer.
 */
template<class VerticeData>
class ShapeBatch : public IShapeDynamic<VerticeData>
{

    bool _bNeedFlush;
    bool _bNeedResize;
    std::vector<VerticeData> *_pVertices;
    std::vector<Index>       *_pIndices;
    TopologyType _topologyType;
    bool _bFixedType;
private:


    enum ShapeStatus { Updated,Changed,JustAdded,ToBeRemoved,Expanded,Contracted,WriteOnly};

    struct ShapeAllocInfo : IShapeWatcher<VerticeData>
    {
        ShapeBatch<VerticeData> *_root;

        int _currNIndices;
        int _currNVertices;
        int _offI;
        int _offV;
        ShapeStatus _status;
        IShapeDynamic<VerticeData>   *_shape;
        bool IsBatch;

        ShapeAllocInfo()
        {
            _root=NULL;
            _shape=NULL;


        }


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

    typename std::list<ShapeAllocInfo>::iterator findShape(IShapeDynamic<VerticeData> *shape)
    {
        assert(shape);
        for (auto it = _v.begin();it!=_v.end();it++)
        {
            if (it->_shape == shape)
                return it;
        }
        return _v.end();

    }




     Index computeNIndices()
     {
         Index acum=0;
         for (ShapeAllocInfo &info : _v)
         {
             if (info._status == ToBeRemoved)
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
             if (info._status == ToBeRemoved)
                 continue;
             if (info.Changed())
                 acum+=info._shape->nVertices();
             else
                acum+=info._currNVertices;
         }
         return acum;
     }

    TopologyType computeBatchType()
    {
        TopologyType type;
        if (_v.empty())
            return EMPTY;
        else
            type = _v.front()._shape->GetTopologyType();


        for (ShapeAllocInfo &info : _v)
        {
            if (info._status == ToBeRemoved)
                continue;
            if (type != info._shape.GetTopologyType())
                return MIXED;

        }
        return type;
    }

    void CheckShapeTopologyType(IShapeDynamic<VerticeData> *shape)
    {
        //Check the type
        if (_bFixedType)
        {
            if (shape->GetTopologyType() != this->_topologyType && (this->_topologyType != MIXED))
            {
                throw new EngineException("Error, shape has TopologyType %d but Batch only accepts topology type %d",(int) shape.GetTopologyType(),(int) this->_topologyType);
            }
        }
        else
        {
            if (_v.empty())
                this->_topologyType=shape->GetTopologyType();
            else if (this->_topologyType != shape->GetTopologyType())
                this->_topologyType= MIXED;
        }


    }




public:

    ShapeBatch(TopologyType type)
    {
        _topologyType=type;
        _bFixedType=true;
    }

    ShapeBatch()
    {
        _topologyType=EMPTY;
        _bFixedType=false;
    }


    virtual ~ShapeBatch(){}



    virtual TopologyType GetTopologyType()
    {
        return _topologyType;

    }

    virtual unsigned nIndices(){
       // assert(_nTotalIndices == computeNIndices());
       // return _nTotalIndices;
        return computeNIndices();
    }

    virtual unsigned nVertices() {
        return computeNVertices();
    }

    virtual void write(IArray<VerticeData> &vertices, IArray<int> &indices)
    {
        unsigned nVerts  = this->nVertices();
        unsigned nIndices= this->nIndices();


        assert(nVerts <= vertices.size() );
        assert(nIndices <= indices.size());

        unsigned offV=0;
       unsigned  offI=0;
       for(ShapeAllocInfo& info : _v)
        {
           Index lV = info._shape->nVertices();
           Index lI = info._shape->nIndices();
           RefArray<VerticeData> vV(vertices,offV,lV);
           RefArray<Index> vI(indices,offI,lI);
           info._shape->write(vV,vI);

           //Correct the indices
           for(int i=0;i<vI.size();i++)
            indices[i]+=offV;

           offV+=lV;
           offI+=lI;

        }
    }




    void NeedResize()
    {
        return _bNeedResize();
    }

    void AddShape(IShapeDynamic<VerticeData> *shape)
    {
        assert(dynamic_cast<ShapeBatch<VerticeData>*>(shape)==nullptr);
        CheckShapeTopologyType(shape);





        //create a  ShapeInfo entry in the list
        _v.push_back(ShapeAllocInfo());

        //Set the entry
        ShapeAllocInfo &info = _v.back();
        info._index = _v.size();
        info._currNIndices = 0;
        info._currNVertices = 0;
        info._status= JustAdded;
        info._shape = shape;
        info._root = this;
        info._shape->AddWatcher(&info);
        this->_bNeedResize=true;
        _bNeedFlush=true;
    }


    void AddBatch(ShapeBatch<VerticeData> &batch)
    {
        this->AddBach((IShapeDynamic<VerticeData>*) batch);
        _v.back().IsBatch=batch;
    }




    void RemoveShape(IShapeDynamic<VerticeData> *shape)
    {
        //find the shape and flag it for removal
        auto it  = this->findShape(shape);
        assert(it!=_v.end());
        if (it != _v.end())
        {
            _bNeedFlush=true;
            it->_status=ToBeRemoved;
        }
        this->_bNeedResize=true;

    }



    /* Rewrite     virtual void ReWriteAll(std::vector<VerticeData> *pvertices,
    the buffer but changing only the minimum it can.
     * This method tries to update only the shapes that are changed.
     * The shapes are writen in order to a buffer.
     * If a shape was marked as changed we rewrite the shape. If this
     * change modifies the number of vertices or indices of the shape,
     * all other shapes from that position on are rewritten;
     * In other words shapes that change their number of indices or vertices are
     * expensive.
     */
        virtual void LazyRewrite(std::vector<VerticeData> *vertices,
                                Index StartV,
                                Index SizeV,
                                std::vector<Index> *indices,
                                Index StartI,
                                Index SizeI,bool bRewriteAll)

        {
            unsigned nVerts  = this->computeNVertices();
            unsigned nIndices= this->computeNIndices();

            assert(nVerts==SizeV);
            assert(nIndices=SizeI);

            _pVertices=vertices;
            _pIndices=indices;

            std::vector<Index> &ind= *indices;



           bool bRewrite = bRewriteAll;
           unsigned offV=StartV;
           unsigned offI=StartI;
           auto it = _v.begin();
           while(it!=_v.end())
            {
               if(it->_status == ToBeRemoved)
               {
                   it=_v.erase(it);
                   bRewrite=true;
               }
               else if (bRewrite || it->Changed())
               {
                Index lV = it->_shape->nVertices();
                Index lI = it->_shape->nIndices();
                if (it->_currNIndices != lI || it->_currNVertices != lV)
                    bRewrite=true;


                if (it->IsBatch)
                {
                    ShapeBatch<VerticeData> *batch= (ShapeBatch<VerticeData>*) it->_shape;
                    batch->LazyRewrite(vertices,offV,lV,indices,offI,lI,bRewrite);
                }
                else
                {
                    RefArray<VerticeData> vV(*_pVertices,offV,lV);
                    RefArray<Index> vI(*_pIndices,offI,lI);
                    it->_shape->write(vV,vI);
                    //Correct the indices
                    for(int i=0;i<vI.size();i++)
                        ind[i]+=offV;

                 }
                it->_currNIndices=lI;
                it->_currNVertices=lV;
                it->_offI=offI;
                it->_offV=offV;
                it->_status=Updated;


                offV+=lV;
                offI+=lI;
               }
               else
               {
                  offI+= it->_currNIndices;
                  offV+= it->_currNVertices;
               }


               it++;

           }
            _bNeedFlush=false;
            _bNeedResize=false;

        }





};







#endif // SHAPEBATCH_H
