#ifndef triangle_h
#define triangle_h
#include "shape.h"

class triangle : public shape
{
    private:
 

    public:
    //getType(string);
    virtual setArea(float);
    virtual setCircumference(float);
    virtual setPosition(float);
    float getArea();
    float getCircumference();
    float setPosition();

    
    
};

#endif
