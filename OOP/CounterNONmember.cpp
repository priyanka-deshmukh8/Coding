#include <iostream>

using namespace std;

class Counter
{
private:
    int count;

public:
    Counter() : count(0)
    {
    }
    Counter(int c) : count(c)
    {
    }
    int getCount()
    {
        return count;
    }
    //friend declaration
    friend Counter operator++(Counter &c);
    friend Counter operator++(Counter &c, int);
};
//----------------------------------------------------------------
//non member operator overloading function for pre-increment
//parameter c is call be reference to reflect the change
Counter operator++(Counter &c)
{
    ++c.count;
    return c;
}
//--------------------------------------------------------------------
//non member operator overloading function for post-increment
//parameter c is call be reference to reflect the change
Counter operator++(Counter &c, int)
{
    Counter temp;
    temp.count = c.count;
    ++c.count;
    return temp;
}
//--------------------------------------------------------------
int main()
{
    Counter c1, c2;

    cout << endl
         << "After initialization:";
    cout << "\nc1=" << c1.getCount(); //display
    cout << "\nc2=" << c2.getCount();
    ++c1;      //c1=1
    c2 = ++c1; //c1=2, c2=2
    cout << endl
         << endl
         << "After increament:";
    cout << "\nc1=" << c1.getCount(); //display again
    cout << "\nc2=" << c2.getCount() << endl;

    ++c1;      //c1=3
    c2 = c1++; //c1=4, c2=3
    cout << endl<< endl << "After increament:";
    cout << "\nc1=" << c1.getCount(); //display again
    cout << "\nc2=" << c2.getCount() << endl;
    return 0;
}