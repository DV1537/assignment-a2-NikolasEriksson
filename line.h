#pragma once
#include "shape.h"
class line :
	public shape
{
public:
	line();
	void constructor(float*, int, float*, float*);
	virtual std::string getType(int, float*, float*);
	virtual float area(int, float*, float*);
	virtual float circumference(int, float*, float*);
	virtual float* position(int, float*, float*);
	virtual bool isConvex(int, float*, float*);
	virtual float distance();
	~line();
};


