#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "shape.h"
#include "polygon.h"
#include "triangle.h"
#include "point.h"
#include "line.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ifstream testFile;
	testFile.open("test.txt");
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(3);
	int coordinates = 0;
	int halfCoordinates = 0;
	float a = 0;

	if (!testFile)
	{
		std::cout << "Could not open the file" << "\n";
		system("PAUSE");
		exit(1);
	}

	if (testFile.is_open())
	{
		while (testFile >> a)
		{
			coordinates += 1;
		}
			if (std::isnan(a) == true || coordinates == 0)
			{
				std::cout << "Wrong input" << "\n";
				system("Pause");
				exit(1);
			}
	}
	halfCoordinates = coordinates / 2;
	float* allCoords = new float[coordinates];
	float* xCoord = new float[halfCoordinates];
	float* yCoord = new float[halfCoordinates];

	testFile.close();
	testFile.open("test.txt");

	for (int i = 0; i < coordinates; i++)
	{
		testFile >> allCoords[i];
	}
	testFile.close();

	polygon polygon;
	polygon.constructor(allCoords,halfCoordinates,xCoord,yCoord);

	if (polygon.getType(halfCoordinates, xCoord, yCoord) == "Polygon")
	{
		std::cout << "The form of all vertices is a " << polygon.getType(halfCoordinates, xCoord, yCoord) << "\n";
		if (polygon.isConvex(halfCoordinates, xCoord, yCoord) == true)
		{
			std::cout << "The polygon is Convex" << "\n";
		}
		else
		{
			std::cout << "The polygon is Concave" << "\n";
		}
		std::cout << "The area of the Polygon is: " << polygon.area(halfCoordinates, xCoord, yCoord) << "\n";
		std::cout << "The circumference is: " << polygon.circumference(halfCoordinates, xCoord, yCoord) << "\n";
		std::cout << "The center position is: (" << polygon.position(halfCoordinates, xCoord, yCoord)[0] << ", " << polygon.position(halfCoordinates, xCoord, yCoord)[1] << ")\n";
	}
	else if (polygon.getType(halfCoordinates, xCoord, yCoord) == "Triangle")
	{
		triangle triangle;
		triangle.constructor(allCoords, halfCoordinates, xCoord, yCoord);
		std::cout << "The form of all vertices is a " << triangle.getType(halfCoordinates, xCoord, yCoord) << "\n";
		std::cout << "The area of the Triangle is: " << triangle.area(halfCoordinates, xCoord, yCoord) << "\n";
		std::cout << "The circumference of the Triangle is: " << triangle.circumference(halfCoordinates, xCoord, yCoord) << "\n";
		std::cout << "The center position is: (" << triangle.position(halfCoordinates, xCoord, yCoord)[0] << ", " << triangle.position(halfCoordinates, xCoord, yCoord)[1] << ")\n";
	}
	else if (polygon.getType(halfCoordinates, xCoord, yCoord) == "Point")
	{
		point point;
		point.constructor(allCoords, halfCoordinates, xCoord, yCoord);
		std::cout << "The form of all vertices is a " << point.getType(halfCoordinates, xCoord, yCoord) << "\n";
		std::cout << "The area of the point is: " << point.area(halfCoordinates, xCoord, yCoord) << "\n";
	}
	else if(polygon.getType(halfCoordinates, xCoord, yCoord) == "Line")
	{
		line line;
		line.constructor(allCoords, halfCoordinates, xCoord, yCoord);
		std::cout << "The form of all vertices is a " << line.getType(halfCoordinates, xCoord, yCoord) << "\n";
		std::cout << "The area of the line is: " << line.area(halfCoordinates, xCoord, yCoord) << "\n";
	}
	
	delete[] allCoords;
	delete[] xCoord;
	delete[] yCoord;
	system("Pause");
	return 0;
}

