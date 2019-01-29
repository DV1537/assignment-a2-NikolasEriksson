#pragma once
#include "shape.h"
#include <cmath>
class triangle :
	public shape
{
protected:
	float distanceOne = 0;
	float distanceTwo = 0;
	float distanceThree = 0;
	float allSides = 0;
public:
	triangle();
	void constructor(float*, int, float*, float*);
	virtual std::string getType(int, float*, float*);
	virtual float area(int, float*, float*);
	virtual float circumference(int, float*, float*);
	virtual float* position(int, float*, float*);
	virtual bool isConvex(int, float*, float*);
	virtual float distance();
	~triangle();
};
