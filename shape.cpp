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
        }
}

std::string shape::getType()
{
    std::string type;
    if(halfCoordinates == 1)
    {
        type = "Point";
    }
    /*else if()
    {
       
        type = "Line";
    }*/   
    else if(halfCoordinates == 3 && xCoord[0] != xCoord[1] && xCoord[0] != xCoord[2])
    {
        type = "Triangle";
    }
    else if(halfCoordinates > 3)
    {
        type = "Polygon";
    }
    return type;
}