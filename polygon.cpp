#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

int main()
{
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);
    int coordinates;
    int halfCoordinates;
    int xBuffer = 0;
    int yBuffer = 1;
    float a = 0;
    float circumference;
    float positionX;
    float positionY;
    float area;
    float total;

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
    int j = (halfCoordinates - 1);
    float *firstArray = new float[coordinates];
    float *xValues = new float[halfCoordinates];
    float *yValues = new float[halfCoordinates];
    float *xCoord = new float[halfCoordinates];
    float *yCoord = new float[halfCoordinates];
    testFile.close();
    testFile.open("test.txt");
        for(int i = 0; i < coordinates; i++)
        {  
        testFile >> firstArray[i];
        }

            for(int i = 0; i < halfCoordinates; i++)
            {
            xCoord[i] = firstArray[xBuffer];
            yCoord[i] = firstArray[yBuffer];
            xBuffer += 2;
            yBuffer += 2;
            std::cout << "The " << i + 1 << " coordinate" << " (" << xCoord[i] << "," << yCoord[i] << ") ";
            }
            std::cout << std::endl;

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
                std::cout << "The area is: " << area << "\n";

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

                std::cout << "The center position is (" << positionX << "," << positionY << ")" << "\n";

    system("pause");
    return 0;


}