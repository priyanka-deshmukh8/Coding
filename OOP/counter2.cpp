//counter2.cpp
#include<iostream>

using namespace std;

class Counter
{
private:
    int count;

public:
    Counter() //default constructor
    {
        count = 0;
    }
    Counter(int c) //parametrized constructor
    {
        count = c;
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
        count++;
    }
    //function to decrement
    void decrement()
    {
        count--;
    }
}; //end of clas
//main function
int main()
{
    Counter c1;
    //default constructor called c1.count=0
    Counter c2(100);
    //parameterized constructor called
    //c2 .count =100
    cout << c1.get_count()
         << c2.get_count() << endl;
    c1.increment();
    c1.increment();
    c2.decrement();
    cout << c1.get_count()  << c2.get_count() << endl;
    return 0;
}
