#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int main()
{
    int sum = 0;
    int a = 0;
    int average = 0;
    int values = 0;

    std::ifstream myReadFile;
    myReadFile.open("negatives.in", std::ios::out); // Put the file that you want to test with.
    int *myArray = new int[values];
    
    if(myReadFile.is_open()) 
    {
        while(myReadFile >> a)
        {
            for(int i = values; i < (values + 1) ; i++) // Reads the numbers in the file and then puts them into the array
            {
                myArray[i] = a;
                std::cout << myArray[i] << " ";
            }
            sum += a;
            values++; 
        }
        average = (sum / values);
    }
    myReadFile.close();
    std::cout << std::endl;
    myReadFile.open("negatives.in", std::ios::out); // Opens the file again to search through which numbers that are greater than average
    if(myReadFile.is_open())
    {
        while(myReadFile >> a)
        {
            if(a > average)
            {
                std::cout << a << " ";
            }
        }
    }
    myReadFile.close();
    std::cout << std::endl;
    
    return 0;
}