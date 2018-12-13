#include "shape.h"
#include <cmath>
#include <string>

shape::shape(){}

shape::shape(float* firstArray, int halfCoordinates)
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

std::string shape::getType()
{
    std::string type;
    if(halfCoordinates > 3)
    {
        type = "Polygon";
    }
    if(halfCoordinates == 3 && xCoord[0] != xCoord[1] && xCoord[0] != xCoord[2])
    {
        type = "Triangle";
    }
    if(halfCoordinates > 1)
    {
        for(int i = 0; i < halfCoordinates; i++)
        {
            if(xCoord[i] == xCoord[i+1] || yCoord[i] == yCoord[i+1])
            {
                type = "Line";
            }
        }
    }
    if(halfCoordinates == 1)
    {
        type = "Point";
    }
    return type;

}