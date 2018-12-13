#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "shape.h"
#include "polygon.h"

int main()
{
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);
    int coordinates;
    int halfCoordinates;
    float a = 0;

    std::ifstream testFile;
    testFile.open("test.txt");

    if(testFile.is_open())
    {
        while(testFile >> a)
        {
            coordinates += 1;
        }
    }
    halfCoordinates = coordinates/2;
    float *firstArray = new float[coordinates];
    float *xCoord = new float[halfCoordinates];
    float *yCoord = new float[halfCoordinates];

    testFile.close();
    testFile.open("test.txt");
        
    for(int i = 0; i < coordinates; i++)
    {  
        testFile >> firstArray[i];
    }
    testFile.close();

    polygon polygonen(firstArray, halfCoordinates);
    std::cout <<"The area is " << polygonen.getArea() << "\n";
    std::cout << "Center coordinates are: " << polygonen.position()[0] << ", " << polygonen.position()[1] << "\n";
    std::cout << "Is the polygon convex or concave? 1 for convex and 0 for concave: " << polygonen.convex() << "\n";
    std::cout << "The circumreference is: " << polygonen.circumference() << "\n";


    system("Pause");
    return 0;
}