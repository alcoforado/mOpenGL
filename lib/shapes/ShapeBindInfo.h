#ifndef SHAPEBINDINFO_H
#define SHAPEBINDINFO_H
#include "AbstractShape.h"
class ShapeBindInfo
{
private:
	bool bNeedUpdate;
	ShapesMngr::Batch *_batch;
public:
	AbstractShape *shape;
	void *_shaderData;
	int nlVert,nlInd;
	unsigned OffV,OffI;

	ShapeBindInfo(ShapesMngr::Batch *batch,AbstractShape *sh,void *pShaderInfoExt)
	{

		_batch=batch;
		shape=sh;
		nlVert=sh->nVertices();
		nlInd=sh->nIndices();
		OffV=-1;
		OffI=-1;
		bNeedUpdate=true;
		_shaderData=pShaderInfoExt;
	}
	void FlagForUpdate(bool b)
	{
		bNeedUpdate=b;
		if (b)
			_batch->FlagForUpdate(true);
	}

	bool NeedUpdate()
	{
		return bNeedUpdate;
	}

	ShapesMngr::Batch& GetBatch(){return *_batch;}

};





#endif // SHAPEBINDINFO_H
