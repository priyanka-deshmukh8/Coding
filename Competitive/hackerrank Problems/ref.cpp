#include<iostream>
 using namespace std;
int main()
{
    int x;
    int &xx=x; //xx is a reference of x
    
    x=10;
    cout<<endl<<x<< xx; //both are 10
    xx++; 
    cout<<endl<<x<< xx; //both are 11

    return 0;
}
