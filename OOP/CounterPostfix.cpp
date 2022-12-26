/* CounterPostfix.cpp: overloaded ++ operator in both prefix and 
postfix without using the concept of nameless temporary object */
#include <iostream>
using namespace std;

class Counter
{
private:
    int count; //count
public:
    Counter() : count(0) //constructor no args
    {
    }
    Counter(int c) : count(c) //constructor, one arg
    {
    }
    int get_count() const //return count
    {
        return count;
    }
    //increment count (prefix)
    Counter operator++()
    {
        Counter temp;
        temp.count = ++count;
        return temp;
    }
    //increment count (postfix)
    Counter operator++(int)
    {
        Counter temp;
        temp.count = count;
        count++;
        return temp;
    }
};
///////////////
int main()
{
    Counter c1, c2; //c1=0, c2=0
    cout << endl
         << "After initialization: ";
    cout << "\nc1=" << c1.get_count(); //display
    cout << "\nc2=" << c2.get_count();
    ++c1;      //c1=1
    c2 = ++c1; //c1=2, c2=2 (prefix)

    cout << endl
         << endl
         << "After pre-increment: ";
    cout << "\nc1=" << c1.get_count(); //display
    cout << "\nc2=" << c2.get_count();
    c1++;      //c1 = 3
    c2 = c1++; //c1=4, c2=3 (postfix)
    cout << endl
         << endl
         << "After post-increment: ";
    cout << "\nc1=" << c1.get_count(); //display again
    cout << "\nc2=" << c2.get_count() << endl;
    return 0;
}