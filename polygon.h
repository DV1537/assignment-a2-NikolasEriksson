#pragma once
#include "shape.h"
class polygon :
	public shape
{
protected:
	float xValue = 0;
	float yValue = 0;
	int lastCounter = 0;
	float lastValueX = 0;
	float lastValueY = 0;
	float positionX = 0;
	float positionY = 0;
public:
	polygon();
	void constructor(float*, int, float*,float*);
	virtual std::string getType(int, float*, float*);
	virtual float area(int, float*, float*);
	virtual float circumference(int, float*, float*);
	virtual float* position(int, float*, float*);
	virtual bool isConvex(int, float*, float*);
	virtual float distance();
	~polygon();
};

