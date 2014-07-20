#pragma once
#include <vector>
#include <globals.h>
#include "AbstractShape.h"
#include <memory>
#include <list>
#include "AdapterFloat4.h"
#include "VectorFunction4x4.h"
typedef struct _Data
{
		Vector4 pos;
		Vector4 color;
} Vertice;


class Batch;

/*
class ShaderExt
{
	
public:
	VectorFunction4x4 *f;
	void update(SubVector<Vertice> &data)
	{
		AdapterFloat4 adpt1(0,sizeof(Vertice));
		AdapterFloat4 adpt2(16,sizeof(Vertice));

		adpt1.Set(&(data[0]),0,data.size());
		adpt2.Set(&(data[0]),0,data.size());

		f->apply(adpt1,adpt2);
	}
};
 
*/

class ShapesMngr
{

	   //ShapesMngr contains batches of shape.
	//Each batch has a list of shapes
public:
	
	class Batch
	{
		friend class ShapesMngr;
	private: 
		ShapesMngr* _mngr;
		std::list<ShapeBindInfo> shapesList;
		Index _nVert,_nInd;
		Index nVertices(){return _nVert;}
		Index nIndices(){return _nInd;}
		unsigned OffV,OffI;
		bool bNeedUpdate;
	
	public:
		Batch(ShapesMngr* owner);
		void AddShape(AbstractShape *shape,void* pShaderInfoExt);
		void Clear();
		void FlagForUpdate(bool b)
		{
			bNeedUpdate=b;
			if (b)
			{
				_mngr->_bNeedUpdate=true;
			}
		
		}
	
	};

private:
	bool _bNeedUpdate;
	Index _nIndices;
	Index _nVertices;

    std::vector<Vertice> _vertHeap;
    std::vector<Index>   _indexHeap;
	std::vector<Batch>   _batches;
	BufferSelectVector4 positionAdapter;
	VertexIndices subIndices;



public:


	ShapesMngr(Index pos_off,size_t structSize)
		:positionAdapter(pos_off,structSize)
	{
		
		_bNeedUpdate=false;
		_nIndices=_nVertices=0;
		
	}

	Batch&  GetBatch(Index i)
	{
		assert(i<_batches.size());
		return _batches[i];
	
	}
	
	Batch& CreateBatch();
	
	
	
	
	
	Index nVertices(){return _nVertices;}
	Index nIndices(){return _nIndices;}
	
	
	std::vector<Vertice>& getVerticesData()
	{
		assert(!NeedUpdate());
		return _vertHeap;

	}

	bool NeedUpdate()
	{
		return _bNeedUpdate;
	}

	std::vector<Index>& getIndicesData()
	{
		assert(!NeedUpdate());
		return _indexHeap;

	}
	

	void ClearAllBatches()
	{
		for(Batch& batch: _batches)
			batch.Clear();
		

	}

	void ComputeAllBatches();


};


