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
    bool convex = true;
    float averageOne;
    float averageTwo;

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
    float *concaveX = new float[halfCoordinates];
    float *concaveY = new float[halfCoordinates];
    float *distanceOne = new float[halfCoordinates];
    float *distanceTwo = new float[halfCoordinates];
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

            for(int i = 0; i < halfCoordinates; i++)
            {
                concaveX[i] = ((xCoord[i] + xCoord[i+1] + xCoord[j])/3);
                if( i+1 >= halfCoordinates)
                {
                    concaveX[i] = ((xCoord[i] + xCoord[0] + xCoord[j])/3);
                }
                concaveY[i] = ((yCoord[i] + yCoord[i+1] + yCoord[j])/3);
                if( i+1 >= halfCoordinates)
                {
                    concaveY[i] = ((yCoord[i] + yCoord[0] + yCoord[j])/3);  
                }
                j = i;
                std::cout << concaveX[i] << "," << concaveY[i] << "\n";
            }

            /*for(int i = 0; i < halfCoordinates; i++)
            {
                distanceOne[i] = sqrt((pow(xCoord[j] - xCoord[i],2)) + (pow(yCoord[j] - yCoord[i],2)));
                j = i;
                std::cout << distanceOne[i] << "\n";
            }
            for(int i = 0; i < halfCoordinates; i++)
            {
                distanceTwo[i] = sqrt((pow(concaveX[j] - concaveX[i],2)) + (pow(concaveY[j] - concaveY[i],2)));
                j = i;
                std::cout << distanceTwo[i] << "\n";
            }*/

            /*for(int i = 0; i < halfCoordinates; i++)
            {
                xCoord[i] - positionX;
                yCoord[i] - positionY;
                concaveX[i] - positionX;
                concaveY[i] - positionY;
                if(xCoord[i] && yCoord[i] < concaveX[i] && concaveY[i])
                {
                    convex = false;
                    if(convex == false)
                    break;
                }
                else
                {
                    convex = true;
                }
            }
                std::cout << convex << "\n";*/
            


    system("pause");
    return 0;


}