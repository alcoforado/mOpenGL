#pragma once
#include "AdapterFloat4.h"
#include "VectorFunction4x4.h"
#include <vector>
#include "Vector4.h" 
class ArrayColorMap : public VectorFunction4x4
{
	std::vector<Vector4> _colors;
public:
	ArrayColorMap(const std::vector<Vector4> &colors)
	{
		_colors=colors;
	}

	virtual void apply(AdapterFloat4 &in,AdapterFloat4 &out)
	{
		assert(in.size() == out.size());
		for (unsigned i=0;i<out.size();i++)
		{
			
			out[i]=_colors[i%_colors.size()];
		}
	}
	virtual ~ArrayColorMap(){}
	
};

