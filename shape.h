#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <iostream>

class shape
{
    protected:
    int halfCoordinates;
    float* xCoord;
    float* yCoord;
    float kValue = 0;
    float deltaX = 0;
    float deltaY = 0;


    public:
    shape();
    shape(float*, int);
    std::string getType();
    /*float area() = 0;
    float circumference() = 0;
    float* position() = 0;
    bool convex() = 0;
    float distance(Shape s) = 0;*/
};

#endif