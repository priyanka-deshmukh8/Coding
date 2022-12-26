//Counter.cpp
#include <iostream>

using namespace std;

//counter class
class Counter
{
private: //member accessible within the class definition only
    /* data */
    int count;

public: //Things accessible out of the class also
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
    Counter c;      //object created space allocated for c.count int var
    c.initialize(); //effectively c.count=0
    //increment counter 3 times
    c.increment();
    c.increment();
    c.increment();

    //display
    cout << c.get_count() << endl;

    //decrement count
    c.decrement();
    cout << c.get_count() << endl;

    return 0;
}
