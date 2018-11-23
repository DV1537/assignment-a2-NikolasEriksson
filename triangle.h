#ifndef triangle_h
#define triangle_h
#include "shape.h"

class triangle : public shape
{
    private:
    int coordinates;
    int xBuffer = 0;
    int yBuffer = 1;
    float a = 0;
    float firstArray[6];
    float *xCoord = new float[3];
    float *yCoord = new float[3];


    public:
    getType();
    virtual setArea();
    virtual setCircumference(float);
    virtual setPosition(float);
    void setType()
    {
    std::ifstream testFile;
    testFile.open("test.txt", std::ios::out);

    if(testFile.is_open())
    {
        while(testFile >> a)
        {
            coordinates += 1;
        }
    }
    testFile.close();
    testFile.open("test.txt", std::ios::out);
        for(int i = 0; i < coordinates; i++)
        {  
        testFile >> firstArray[i];
        }
            for(int i = 0; i < coordinates/2; i++)
            {
            xCoord[i] = firstArray[xBuffer];
            yCoord[i] = firstArray[yBuffer];
            xBuffer += 2;
            yBuffer += 2;
            std::cout << "The " << i + 1 << " coordinate" << " (" << xCoord[i] << "," << yCoord[i] << ") ";
            }
            std::cout << std::endl;
    }
    
    float getArea();
    float getCircumference();
    float setPosition();

    
    
};

#endif
