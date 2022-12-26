#include <iostream>
#include <malloc.h>
using namespace std;

class Distance //English Distance class
{
private:
    int feet;
    float inches;

public:
    Distance(int ft = 0, float in = 0.0) : feet(ft), inches(in)
    {
        cout << "Constructor called" << endl;
    }
    void getDistance()
    {
        cout << "\nEnter feet:";
        cin >> feet;
        cout << "Enter inches:";
        cin >> inches;
    }
    void showDistance()
    {
        cout << feet << "\'-" << inches << '\"' << endl;
    }
};
int main()
{
    Distance *p;
    int n, i;
    n = 3;
    //allocate dynamically
    p = new Distance[n]; //ctor called n times in the order
    //loop to read the data
    for (i = 0; i < n; ++i)
    {
        cout << endl
             << "Enter data for object " << i + 1 << endl;
        p[i].getDistance();
    }
    //loop to display the data
    for (i = 0; i < n; ++i)
    {
        cout << endl
             << "You Enter data for object" << i + 1 << endl;
        (p + i)->showDistance();
    }
    delete[] p;
    return 0;
}