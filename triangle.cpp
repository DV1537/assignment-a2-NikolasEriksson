#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

int main()
{
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);
    int coordinates;
    int xBuffer = 0;
    int yBuffer = 1;
    float a = 0;
    float firstArray[6];
    float *xCoord = new float[3];
    float *yCoord = new float[3];
    float sideOne;
    float sideTwo;
    float sideThree;
    float distanceOne;
    float distanceTwo;
    float distanceThree;
    float area;
    float circumference;
    float positionX;
    float positionY;
    float allSides;

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
            
            distanceOne = (pow(xCoord[1] - xCoord[0],2)) + (pow(yCoord[1] - yCoord[0],2));
            distanceTwo = (pow(xCoord[2] - xCoord[0],2)) + (pow(yCoord[2] - yCoord[0],2));
            distanceThree = (pow(xCoord[2] - xCoord[1],2)) + (pow(yCoord[2] - yCoord[1],2));

            sideOne = sqrt(distanceOne);
            sideTwo = sqrt(distanceTwo);
            sideThree = sqrt(distanceThree);
            allSides = (sideOne + sideTwo + sideThree)/2;

            area = sqrt((allSides*(allSides - sideOne)) * (allSides - sideTwo) * (allSides - sideThree));
         
            positionX = ((xCoord[0] + xCoord[1] + xCoord[2])/3);
            positionY = ((yCoord[0] + yCoord[1] + yCoord[2])/3);
            circumference = sideOne + sideTwo + sideThree;

            std::cout << "The area for the Triangle is: " << area << "\n";
            std::cout << "The circumference is: " << circumference << "\n";
            std::cout << "The center position is (" << positionX << "," << positionY << ")" << "\n";
            
            system("pause");
            return 0;
}