#include "polygon.h"

polygon::polygon()
{

}

void polygon::constructor(float* allCoords, int halfCoordinates, float* xCoord, float* yCoord)
{
		int xBuffer = 0;
		int yBuffer = 1;

		for (int i = 0; i < halfCoordinates; i++)
		{
			xCoord[i] = allCoords[xBuffer];
			yCoord[i] = allCoords[yBuffer];
			xBuffer += 2;
			yBuffer += 2;
			std::cout << "The " << i + 1 << " coordinate" << " (" << xCoord[i] << ", " << yCoord[i] << ") ";
		}
		std::cout << std::endl;
}

std::string polygon::getType(int halfCoordinates, float* xCoord, float* yCoord)
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

float polygon::area(int halfCoordinates, float* xCoord, float* yCoord)
{
	float total = 0;
	int j = (halfCoordinates - 1);
	for (int i = 0; i < halfCoordinates; i++)
	{
		total += (xCoord[j] + xCoord[i]) * (yCoord[j] - yCoord[i]);
		j = i;
	}
	if (total < 0)
	{
		ar = std::abs(total / 2.0f);
	}
	else
	{
		ar = (total / 2.0f);
	}
	if (convex == true || ar == 0)
	{
		return -1;
	}
	return ar;
}

float polygon::circumference(int halfCoordinates, float* xCoord, float* yCoord)
{
	for (int i = 0; i < (halfCoordinates - 1); i++)
	{
		xValue = pow(xCoord[i + 1] - xCoord[i], 2);
		yValue = pow(yCoord[i + 1] - yCoord[i], 2);
		circum += sqrt(xValue + yValue);
		lastCounter++;
	}

	lastValueX = pow(xCoord[lastCounter] - xCoord[0], 2);
	lastValueY = pow(yCoord[lastCounter] - yCoord[0], 2);
	circum += sqrt(lastValueX + lastValueY);
	return circum;
}

float* polygon::position(int halfCoordinates, float* xCoord, float* yCoord)
{
	for (int i = 0; i < halfCoordinates; i++)
	{
		positionX += xCoord[i];
	}
	positionX /= halfCoordinates;

	for (int i = 0; i < halfCoordinates; i++)
	{
		positionY += yCoord[i];
	}
	positionY /= halfCoordinates;
	pos[0] = positionX;
	pos[1] = positionY;
	return pos;
}

bool polygon::isConvex(int halfCoordinates, float* xCoord, float* yCoord)
{

	for (int i = 0; i < halfCoordinates; i++) {
		float deltaX1 = xCoord[(i + 2) % halfCoordinates] - xCoord[(i + 1) % halfCoordinates];
		float deltaY1 = yCoord[(i + 2) % halfCoordinates] - yCoord[(i + 1) % halfCoordinates];
		float deltaX2 = xCoord[i] - xCoord[(i + 1) % halfCoordinates];
		float deltaY2 = yCoord[i] - yCoord[(i + 1) % halfCoordinates];

		float deltaProduct = (deltaX1 * deltaY2) - (deltaX2 * deltaY1);

		if (i == 0)
		{
			convex = deltaProduct > 0;
		}
		else if (convex != (deltaProduct > 0))
		{
			return false;
		}
	}
	return true;
}

float polygon::distance()
{
	return dist;
}

polygon::~polygon()
{
	
}