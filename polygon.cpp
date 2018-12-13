#include "polygon.h"
#include <iostream>
#include <cmath>

polygon::polygon(){}

polygon::polygon(float* firstArray, int halfCoordinates)
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

float polygon::getArea()
{
    float total = 0;
    int j = (halfCoordinates - 1);
    for(int i = 0; i < halfCoordinates; i++)
    {
        total += (xCoord[j] + xCoord[i]) * (yCoord[j]-yCoord[i]);
        j = i; 
    }
    area = (total/2);
    if(area < 0)
    {
    area = (abs(total/2));
    }
    return area;
}

float polygon::circumference()
{
    float total = 0;
    float xValue = 0;
    float yValue = 0;
    int lastCounter = 0;
    float lastValueX = 0;
    float lastValueY = 0;
    for(int i = 0; i < (halfCoordinates - 1); i++)
    {
        xValue = pow(xCoord[i+1] - xCoord[i],2);
        yValue = pow(yCoord[i+1] - yCoord[i],2);
        total += sqrt(xValue + yValue);
        lastCounter++;
    }

    lastValueX = pow(xCoord[lastCounter] - xCoord[0],2);
    lastValueY = pow(yCoord[lastCounter] - yCoord[0],2);
    total += sqrt(lastValueX + lastValueY);

    return total;
}

float* polygon::position()
{
float positionX = 0;
float positionY = 0;
    for(int i = 0; i < halfCoordinates; i++)
    {
        positionX += xCoord[i];
    }
        positionX /= halfCoordinates;

    for(int i = 0; i < halfCoordinates; i++)
    {
        positionY += yCoord[i];
    }
        positionY /= halfCoordinates;
    centerPosition[0] = positionX;
    centerPosition[1] = positionY;

    return centerPosition;
}

bool polygon::convex()
{
    bool convex = false;
    
    for(int i = 0; i < halfCoordinates; i++){
        float deltaX1 = xCoord[(i+2) % halfCoordinates] - xCoord[(i+1) % halfCoordinates];
        float deltaY1 = yCoord[(i+2) % halfCoordinates] - yCoord[(i+1) % halfCoordinates];
        float deltaX2 = xCoord[i] - xCoord[(i+1) % halfCoordinates];
        float deltaY2 = yCoord[i] - yCoord[(i+1) % halfCoordinates];

        float deltaProduct = (deltaX1 * deltaY2) - (deltaX2 * deltaY1); 

        if(i == 0)
        {
            convex = deltaProduct > 0;
        }
        else if(convex != (deltaProduct > 0))
        {
            return false;
        }
    }
    return true;
}

polygon::~polygon(){}
            