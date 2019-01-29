#pragma once
#include <string>
#include <iostream>
class shape
{
protected:
	std::string type = "";
	float ar = 0;
	float circum = 0;
	float pos[2] = { 0 };
	bool convex = true;
	float dist = 0;

public:
	shape();
	virtual std::string getType(int, float*, float*) = 0;
	virtual float area(int, float*, float*) = 0;
	virtual float circumference(int, float*, float*) = 0;
	virtual float* position(int, float*, float*) = 0;
	virtual bool isConvex(int, float*, float*) = 0;
	virtual float distance() = 0;

	~shape();
};
