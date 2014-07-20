#pragma once

#include <vector>
#include <assert.h>

template<class T>
class SubVector
{
	Index _size;
	std::vector<T>  *_p;
	Index _off;
public:

	SubVector()
	{
		_p=NULL;
		_size=0;
		_off=0;
	}

	SubVector(std::vector<T> &v,unsigned i1,unsigned i2)
	{
		reinit(v,i1,i2);
	}

	void reinit(std::vector<T> &v,unsigned i1,unsigned i2)
	{
		assert(i1<i2);
		assert(i2<v.size());
		_p=&v;
		_size=i2-i1+1;
		_off=i1;
	}

	T& operator[](Index index){assert(index<_size);return (*_p)[index+_off];}
	const T& operator[](Index index) const {assert(index<_size);return (*_p)[index+_off];}

	Index size(){return _size;}

	~SubVector(void)
	{
	}
};

