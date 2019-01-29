#include "point.h"

point::point()
{
}

void point::constructor(float* allCoords, int halfCoordinates, float* xCoord, float* yCoord)
{
	int xBuffer = 0;
	int yBuffer = 1;

	for (int i = 0; i < halfCoordinates; i++)
	{
		xCoord[i] = allCoords[xBuffer];
		yCoord[i] = allCoords[yBuffer];
		xBuffer += 2;
		yBuffer += 2;
	}
}


std::string point::getType(int halfCoordinates, float* xCoord, float* yCoord)
{
	float* deltaY = new float[halfCoordinates];
	float* deltaX = new float[halfCoordinates];
	float* kValue = new float[halfCoordinates];
	for (int i = 0; i < (halfCoordinates - 1); i++)
	{
		deltaY[i] = yCoord[i + 1] - yCoord[i];
		deltaX[i] = xCoord[i + 1] - xCoord[i];
		kValue[i] = (deltaY[i] / deltaX[i]);
	}
	if (halfCoordinates > 1)
	{
		for (int i = 0; i < (halfCoordinates - 1); i++)
		{
			if (kValue[i] == kValue[i + 1])
			{
				type = "Line";
			}
		}
	}
	if (halfCoordinates == 1)
	{
		type = "Point";
	}
	else if (halfCoordinates == 3 && xCoord[0] != xCoord[1] && xCoord[0] != xCoord[2] && yCoord[0] != yCoord[1] && yCoord[0] != yCoord[2])
	{
		type = "Triangle";
	}
	else if (type != "Triangle" && type != "Line" && type != "Point")
	{
		type = "Polygon";
	}
	delete[] deltaX;
	delete[] deltaY;
	delete[] kValue;
	return type;
}

float point::area(int halfCoordinates, float* xCoord, float* yCoord)
{
	return -1;
}

float point::circumference(int halfCoordinates, float* xCoord, float* yCoord)
{
	return circum;
}

float* point::position(int halfCoordinates, float* xCoord, float* yCoord)
{
	return pos;
}

bool point::isConvex(int halfCoordinates, float* xCoord, float* yCoord)
{
	return true;
}

float point::distance()
{
	return dist;
}

point::~point()
{
}
