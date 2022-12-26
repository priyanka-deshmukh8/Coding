#include<iostream>
using namespace std;
float Power(float x,int n=2);

int main()
{
    float x;
    int n;
    x=5.0; n=3;
    cout<<Power(x,n);
    cout<<Power(x);
    return 0;
}
float power(float x,int n)
{
    float res=1.0;
    for(int i=0;i<n;i++)
    {
        res*=x;
        return res;
    }
}