//counter1.cpp
#include <iostream>

using namespace std;
//counter class
class Counter
{
private: // things accessible within
    //the class definition only
    int count;

public: // things accessible out of the class also
    //function to initialize
    void initialize(int c = 0)
    {
        count = c;
    }
    //function to increment
    void increment()
    {
        ++count;
    }
    //function to decrement
    void decrement()
    {
        --count;
    }
    //getter function
    int get_count()
    {
        return count;
    }
}; //end of class
//main function
int main()
{
    Counter c; // object created, space allocated
    //for c.count integer variable
    c.initialize(); // effectively c.count = 0
    //increment counters 3 times.
    c.increment(); // effectively c.count++
    c.increment();
    c.increment();
    //display
    cout << c.get_count() << endl;
    //decrement count
    c.decrement(); //effectively c.count- -
    //display
    cout << c.get_count() << endl;
    return 0;
}