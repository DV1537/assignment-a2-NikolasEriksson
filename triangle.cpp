#include "triangle.h"



triangle::triangle()
{
}

void triangle::constructor(float* allCoords, int halfCoordinates, float* xCoord, float* yCoord)
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

std::string triangle::getType(int halfCoordinates, float* xCoord, float* yCoord)
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

float triangle::area(int halfCoordinates, float* xCoord, float* yCoord)
{
	distanceOne = (pow(xCoord[1] - xCoord[0], 2)) + (pow(yCoord[1] - yCoord[0], 2));
	distanceTwo = (pow(xCoord[2] - xCoord[0], 2)) + (pow(yCoord[2] - yCoord[0], 2));
	distanceThree = (pow(xCoord[2] - xCoord[1], 2)) + (pow(yCoord[2] - yCoord[1], 2));
	distanceOne = sqrt(distanceOne);
	distanceTwo = sqrt(distanceTwo);
	distanceThree = sqrt(distanceThree);
	allSides = (distanceOne + distanceTwo + distanceThree) / 2;
	ar = sqrt((allSides*(allSides - distanceOne)) * (allSides - distanceTwo) * (allSides - distanceThree));
	return ar;
}

float triangle::circumference(int halfCoordinates, float* xCoord, float* yCoord)
{
	distanceOne = (pow(xCoord[1] - xCoord[0], 2)) + (pow(yCoord[1] - yCoord[0], 2));
	distanceTwo = (pow(xCoord[2] - xCoord[0], 2)) + (pow(yCoord[2] - yCoord[0], 2));
	distanceThree = (pow(xCoord[2] - xCoord[1], 2)) + (pow(yCoord[2] - yCoord[1], 2));
	distanceOne = sqrt(distanceOne);
	distanceTwo = sqrt(distanceTwo);
	distanceThree = sqrt(distanceThree);
	circum = distanceOne + distanceTwo + distanceThree;
	return circum;
}

float* triangle::position(int halfCoordinates, float* xCoord, float* yCoord)
{
	float positionX = ((xCoord[0] + xCoord[1] + xCoord[2]) / 3);
	float positionY = ((yCoord[0] + yCoord[1] + yCoord[2]) / 3);
	pos[0] = positionX;
	pos[1] = positionY;
	return pos;
}

bool triangle::isConvex(int halfCoordinates, float* xCoord, float* yCoord)
{
	return true;
}

float triangle::distance()
{
	return dist;
}

triangle::~triangle()
{
}
