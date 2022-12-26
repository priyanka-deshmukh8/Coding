#include<iostream>
using namespace std;
class Distance
{
    private:
    int feet;
    float inches;
    public:
    Distance(int ft=0,float in =0.0)
    {
        feet =ft; inches=in;
        show();
        cout<<endl<<"Ctor called"<<endl;
    }
    void show()
    {
        cout<<feet<<"\'-"<<inches<<"\' "<< endl;

    }
    ~Distance()
    {
        show();
        cout<<endl<<"Dtor called"<<endl;
    }
}; //end of class
//////////////
int main()
{
    Distance d(1,1.0F);
    Distance* dp;
    dp=&d;
    d.show();

    cout<<endl;
    return 0;
}