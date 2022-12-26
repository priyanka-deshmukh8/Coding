#include <iostream>

using namespace std;

class Sample
{
    int *px;

public:
    //default constructor
    Sample(int x = 0)
    {
        cout << "Constructor executing,space being allocated" << endl;
    }
    //setter function
    void set(int x = 0)
    {
        *px = x;
    }
    //display function
    void Display()
    {
        cout << *px << endl;
    }
    //Destructor
    ~Sample()
    {
        cout << endl
             << "Destructor executing,space being released" << endl;
        delete px;
    }
}; //end of class
int main()
{
    Sample *sp;

    cout << endl
         << "Constructor called after it" << endl;
    sp = new Sample(100);

    sp->Display();
    sp->set();
    sp->Display();

    delete sp; //dtor called
    cout << "Distructor has been called before it" << endl;
    return 0;
}