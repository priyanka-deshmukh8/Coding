//counter class with ++ overload uses unnamed temporary object
#include <iostream>

using namespace std;

class Counter
{
private:
    int count;

public:
    Counter() : count(0) //ctor no args
    {
    }
    Counter(int c) : count(c) //constructor,one arg
    {
    }
    int getCount()
    {
        return count;
    }
    Counter operator++()
    {
        ++count;
        //increment count, then return an unnamed temporary object
        // initialized to this count; constructor necessary
        return Counter(count);
    }
};

int main()
{
    Counter c1,c2;

    cout<<"\nc1="<<c1.getCount();
    cout<<"\nc2="<<c2.getCount();
    ++c1;
    c2=++c1;
    cout<<"\nc1="<<c1.getCount();  //display again
    cout<<"\nc2="<<c2.getCount()<<endl;
    return 0;
}