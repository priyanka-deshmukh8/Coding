#include <iostream>
#include <process.h>
#include <malloc.h>

using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance(int ft = 0, float in = 0.0) : feet(ft), inches(in)
    {
    }
    void set()
    {
        cout << "Enter feet:";
        cin >> feet;
    }
    void show()
    {
        cout << feet << "\'-" << inches << '\"' << endl;
    }
    ~Distance()
    {
        cout << "Destructor call here for object:";
        show();
    }
}; //end of class
/////////////////
int main()
{
    Distance *d1, *d2, *d3; //no ctor called here
    d1 = new Distance();    //default ctor called here
    if (d1 == NULL)
    {
        cout << "Memory not available" << endl;
        exit(1);
    }
    d2 = new Distance(10, 6.7f);
    if (d2 == NULL)
    {
        cout << "Memory not available" << endl;
        exit(1);
    }
    d3 = (Distance *)malloc(sizeof(Distance)); //ctor not called here
    if (d3 == NULL)
    {
        cout << "Memory not available" << endl;
        exit(1);
    }
    cout << endl
         << endl
         << "Show being called" << endl;
    d1->show();
    d2->show();
    d3->show();

    d3->set();
    d3->show();

    delete d1;//dtor called here
    delete d2;//dtor called here
    free(d3);//no dtor called here

    return 0;
}