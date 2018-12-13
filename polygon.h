#ifndef polygon_h
#define polygon_h
#include "shape.h"

class polygon : public shape
{
    protected:
        int halfCoordinates;
        float* xCoord;
        float* yCoord;
        float area = 0;
        float centerPosition[2];
        float *kValue;
        

    public:
        polygon();
        polygon(float*, int);
        float getArea();
        float circumference();
        float* position();
        bool convex();
        
        ~polygon();
};

#endif