#ifndef SHAPE_H
#define SHAPE_H

class shape
{
    public:
    //std::string getType() = 0;
    virtual float area() = 0;
    virtual float circumference() = 0;
    virtual float position() = 0;
    //void isConvex() = 0;
    //float distance(Shape s) = 0;
    

};

#endif