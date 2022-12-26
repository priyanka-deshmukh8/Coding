/*  Design a class Cartesian containing two members x and y. The member
functions are:  o Constructors using member initializer list.
                o Set function
                o Display function.*/
#include <iostream>
using namespace std;

class Cartesian
{
private:
    double x, y;

public:
    Cartesian()
    {
        x = 0;
        y = 0;
    }
    void setXY(double a, double b)
    {
        x = a;
        y = b;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void show() 
    {
        cout << "Coordinates are :(" << getX() << "," << getY() << ")" << endl;
    }
};
int main() //main function
{          //objects
    Cartesian c1, c2;
    c1.setXY(5, 10.56);
    c1.show();
    c2.setXY(50, 100);
    c2.show();

    return 0;
}