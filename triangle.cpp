#include "triangle.h"
#include <cmath>

triangle::triangle(){}

triangle::triangle(float* firstArray, int halfCoordinates)
{
    this->xCoord = new float[halfCoordinates];
    this->yCoord = new float[halfCoordinates];
    this->halfCoordinates = halfCoordinates;
    
    int xBuffer = 0;
    int yBuffer = 1;

        for(int i = 0; i < halfCoordinates; i++)
        {
            xCoord[i] = firstArray[xBuffer];
            yCoord[i] = firstArray[yBuffer];
            xBuffer += 2;
            yBuffer += 2;
            std::cout << "The " << i + 1 << " coordinate" << " (" << xCoord[i] << "," << yCoord[i] << ") ";
        }
        std::cout << std::endl;
}

float triangle::circumference()
{
    distanceOne = (pow(xCoord[1] - xCoord[0],2)) + (pow(yCoord[1] - yCoord[0],2));
    distanceTwo = (pow(xCoord[2] - xCoord[0],2)) + (pow(yCoord[2] - yCoord[0],2));
    distanceThree = (pow(xCoord[2] - xCoord[1],2)) + (pow(yCoord[2] - yCoord[1],2));
    sqrt(distanceOne);
    sqrt(distanceTwo);
    sqrt(distanceThree);
    circumfer = distanceOne + distanceTwo + distanceThree;
    return circumfer;
}

float triangle::getArea()
{
    distanceOne = (pow(xCoord[1] - xCoord[0],2)) + (pow(yCoord[1] - yCoord[0],2));
    distanceTwo = (pow(xCoord[2] - xCoord[0],2)) + (pow(yCoord[2] - yCoord[0],2));
    distanceThree = (pow(xCoord[2] - xCoord[1],2)) + (pow(yCoord[2] - yCoord[1],2));
    sqrt(distanceOne);
    sqrt(distanceTwo);
    sqrt(distanceThree);
    allSides = (distanceOne + distanceTwo + distanceThree)/2;
    area = sqrt((allSides*(allSides - distanceOne)) * (allSides - distanceTwo) * (allSides - distanceThree));
    return area;
}

float* triangle::position()
{
    float positionX = ((xCoord[0] + xCoord[1] + xCoord[2])/3);
    float positionY = ((yCoord[0] + yCoord[1] + yCoord[2])/3);
    centerpoint[0] = positionX;
    centerpoint[1] = positionY;
    return centerpoint;
}
            
         

triangle::~triangle(){}