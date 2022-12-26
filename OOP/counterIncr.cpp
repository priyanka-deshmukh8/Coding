//counterIncr.cpp : counter with constructor
#include <iostream>

using namespace std;

class Counter
{
private:
    int count;
    const int incr;

public:
    Counter(int c = 0, int in = 1) : count(c), incr(in)
    {
    }
    //function to set value
    void set_count(int c)
    {
        count = c;
    }
    //function to get value
    int get_count()
    {
        return count;
    }
    //function to increment
    void increment()
    {
        count += incr;
    }
    //function to decrement
    void decrement()
    {
        count -= incr;
    }
}; //end of class
//main function
int main()
{
    Counter c1;          //default constructor called c1.count=0
    Counter c2(100, 10); //parameterized constructor called c2 .count =100
    cout << endl
         << c1.get_count()
         << endl
         << c2.get_count() << endl;
    c1.increment();
    c1.increment();
    c2.increment();
    cout << endl
         << c1.get_count()
         << endl
         << c2.get_count() << endl;
    return 0;
}