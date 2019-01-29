#include "shape.h"

shape::shape()
{

}

std::string shape::getType(int halfCoordinates, float* xCoord, float* yCoord)
{
	return type;
}

float shape::area(int halfCoordinates, float* xCoord, float* yCoord)
{
	return ar;
}

float shape::circumference(int halfCoordinates, float* xCoord, float* yCoord)
{
	return circum;
}

float* shape::position(int halfCoordinates, float* xCoord, float* yCoord)
{
	return pos;
}

bool shape::isConvex(int halfCoordinates, float* xCoord, float* yCoord)
{
	return true;
}

float shape::distance()
{
	return dist;
}

shape::~shape()
{
}