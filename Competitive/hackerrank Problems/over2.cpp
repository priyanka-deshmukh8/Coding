#include<iostream>
using namespace std;
struct Complex
{
    float real;
    float img;
};

void Display(int);
void Display(Complex);

int main()
{
    int x=10;
    Complex c;
    c.real=5.0;
    c.img=7.0;

    Display(x);
    Display(c);
    
    return 0;
}

void Display(int a)
{
    cout<<endl<<"Integer is:"<<a;
}

void Display(Complex b)
{
    cout<<endl<<"Real Part is:"<<b.real;
    cout<<endl<<"imaginary  Part is:"<<b.img;

}

