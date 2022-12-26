#include<iostream>
using namespace std;

void change(int &x,int y);

int main()
{
    int a=10,
    b=20;
    change(a,b);
    cout<<endl<<a<<b;
    return 0;

}
void change(int &x,int y)
{
    cout<<endl<<x<<y; //1020
    x++;
    y++;
    cout<<endl<<x<<y; //1121

}