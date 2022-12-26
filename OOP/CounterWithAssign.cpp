#include<iostream>

using namespace std;

class Counter
{
    private:
    int count;
    public:
    //constructor
    Counter(int c=0):count(c)
    { }
    //setter function
    void set(int c=0)
    {
        count=c;
    }
    //display function
    void display()
    {
        cout<<endl<<"count="<<count;
    }
    //function to increment with support to assignment operator
    Counter operator++()
    {
    Counter temp;
    temp.count=++count;
    return temp;
    }
    //function to decrement with support to assignment operator
    Counter operator--()
    {
        Counter temp;
        temp.count=--count;
        return temp;
    }
};//end of counter class
int main()
{
    Counter c1(100),c2;
    ++c1;
    c2=++c1;
    c1.display();
    c2.display();

    c2=--c1;
    c1.display();
    c2.display();
    return 0;
}