#ifndef polygon_h
#define polygon_h

class polygon : public shape
{
    protected:
        std::string type = "Polygon";
        int halfCoordinates;
        float* xCoord;
        float* yCoord;
        float area = 0;
        float centerPosition[2];
        float *kValue;
        

    public:
        polygon();
        polygon(float*, int);
        //std::string getType();
        float getArea();
        float circumference();
        float* position();
        bool convex();
        
        ~polygon();
};

#endif