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
    float *firstArray = new float[coordinates];
    float *xCoord = new float[coordinates];
    float *yCoord = new float[coordinates];
    float *xValues = new float[coordinates];
    float *yValues = new float[coordinates];
    float circumference;
    float positionX;
    float positionY;

    std::ifstream testFile;
    testFile.open("test.txt");

    if(testFile.is_open())
    {
        while(testFile >> a)
        {
            coordinates += 1;
        }
    }
    testFile.close();
    testFile.open("test.txt");
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

            for(int i = 0; i < coordinates/2; i++)
            {
                xValues[i] += xCoord[i] * yCoord[i+1];
                if(yCoord[i+1] <= 0)
                {
                    yCoord[i+1] = yCoord[i];
                    xValues[i] += xCoord[i] * yCoord[0];
                }
                std::cout << xValues[i] << "\n";
            }

            for(int i = 0; i < coordinates/2; i++)
            {
                yValues[i] += yCoord[i] * xCoord[i+1];
                if(xCoord[i+1] <= 0)
                {
                    xCoord[i+1] = xCoord[i];
                    yValues[i] += yCoord[i] * xCoord[0];
                }
                std::cout << yValues[i] << "\n";
            }

            for(int i = 0; i < coordinates/2; i++)
            {
                positionX += xCoord[i];
            }
                positionX /= (coordinates/2);

            for(int i = 0; i < coordinates/2; i++)
            {
                positionY += yCoord[i];
            }
                positionY /= (coordinates/2);

                std::cout << "The center position is (" << positionX << "," << positionY << ")" << "\n";

    system("pause");
    return 0;


}