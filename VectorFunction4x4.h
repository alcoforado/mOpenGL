#pragma once
#include "AdapterFloat4.h"
class VectorFunction4x4
{
public:
	VectorFunction4x4(void);
	virtual void apply(BufferSelectVector4 &in,BufferSelectVector4 &out)=0;
	virtual ~VectorFunction4x4(void);

};

