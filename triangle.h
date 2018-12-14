#ifndef triangle_h
#define triangle_h
#include "shape.h"

class triangle : public shape
{
    protected:
    float distanceOne = 0;
    float distanceTwo = 0;
    float distanceThree = 0;
    float circumfer = 0;
    int halfCoordinates;
    float* xCoord;
    float* yCoord;
    float allSides = 0;
    float area = 0;
    float centerpoint[2];

    public:
    triangle();
    triangle(float*, int);
    float getArea();
    float circumference();
    float* position();

    ~triangle();

    
    
};

#endif
