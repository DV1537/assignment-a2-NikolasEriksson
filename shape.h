#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class shape
{
    public:
    std::string getType() = 0;
    float area() = 0;
    float circumference() = 0;
    float position() = 0;
    void isConvex() = 0;
    float distance(Shape s) = 0;
    

};

#endif