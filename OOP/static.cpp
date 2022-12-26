#include <iostream>

using namespace std;

class Sample
{
private:
    int od;         //instance variable
    static int cd;  //class variable, this is declaration only

public:
    Sample():od(0)
    {}
    Sample(int o)
    {setOd(o);}

    void setOd(int o)
    {od=o;}
    int getOd() const
    {return od;}

    //functions accessing only static member data should be static
    //or static member functions cannot access non-static data
    static void setCd(int c)
    {cd=c;}
    static int getCd()
    {return cd;}

    //non static functions can access static function
    //but static functions cannot access non static functions or non static data
    void show() const
    {cout<<"Object data value: "<<getOd()<<" Class data value: "<<getCd()<<endl;}
};

//essential definition of class data, and initialization
int Sample::cd=0;

int main()
{
    //static context exists even before creating any object
    cout<<"Value of static data is: "<<Sample::getCd()<<endl<<endl;

    Sample s1, s2(100);

    s1.setOd(10);

    s1.show();
    s2.show();

    s1.setCd(50); //change in the value of class data
    s1.show();
    s2.show();

    s2.setCd(80); //change in the value of class data
    s1.show();
    s2.show();

    //static member do not contribute to the size of the Object
    cout<<"Size is: "<<sizeof(s1)<<endl;

    return 0;
}