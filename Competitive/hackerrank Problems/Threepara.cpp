#include<iostream>
using namespace std;

void change(int ,int&,const int&); //prototype
int main()
{
    int a=10,b=20,c=30;
    cout<<endl<<a<<b<<c;
    change(a,b,c);
    cout<<endl<<a<<b<<c;
    return 0;
}
void change(int x ,int& y,const int& z)
{
    cout<<endl<<x<<y<<z;
    x++;
    y++;
    //z++;
    cout<<endl<<x<<y<<z;
       
}