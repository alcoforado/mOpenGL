
#include "ShapesMngr.h"
#include "ShapeBindInfo.h"



	ShapesMngr::Batch& ShapesMngr::CreateBatch()
	{
		Batch batch(this);
		_batches.push_back(batch);
		return _batches[_batches.size()-1];
	}
	
	ShapesMngr::Batch::Batch(ShapesMngr* owner)
{
	OffV=OffI=INVALID_INDEX;
	_nVert=_nInd=0;
	_mngr=owner;	
	bNeedUpdate=false;
}

void ShapesMngr::Batch::AddShape(AbstractShape *shape,void *pShaderInfoExt)
{


	shapesList.push_back(ShapeBindInfo(this,shape,pShaderInfoExt));
	_nVert+=shape->nVertices();
	_nInd+=shape->nIndices();
	_mngr->_nIndices+=shape->nIndices();
	_mngr->_nVertices+=shape->nVertices();
	bNeedUpdate=true;
	_mngr->_bNeedUpdate=true;
}

void ShapesMngr::Batch::Clear()
{
	shapesList.clear();
	_mngr->_nIndices-=_nInd;
	_mngr->_nVertices-=_nVert;
	_nInd=_nVert=0;
	OffV=OffI=INVALID_INDEX;
	bNeedUpdate=true;
	_mngr->_bNeedUpdate=true;

}

void 	ShapesMngr::ComputeAllBatches()
	{
		if (!NeedUpdate())
			return;
		//Allocate the heap if necessary
		if (_nVertices != _vertHeap.size())
			_vertHeap.resize(_nVertices);
		if (_nIndices != _indexHeap.size())
			_indexHeap.resize(_nIndices);

		
		Index *baseInd=&(_indexHeap[0]);
		Vertice *baseVert= &(_vertHeap[0]);

		unsigned OffV=0,OffI=0;
		//run through the batches
		
		for(Batch& batch: _batches)
		{
		
			batch.OffV=OffV;
			batch.OffI=OffI;
			for(ShapeBindInfo& shInfo: batch.shapesList)
			{
				this->subIndices.Set(baseInd,OffI,shInfo.nlInd);
				this->positionAdapter.Set(baseVert,OffV,shInfo.nlVert);

				shInfo.shape->write(positionAdapter,subIndices);
				
				OffV+=shInfo.nlVert;
				OffI+=shInfo.nlInd;
				shInfo.FlagForUpdate(false);
			}
			assert(OffV-batch.OffV == batch.nVertices());
			assert(OffI-batch.OffI == batch.nIndices());
		}
	}
