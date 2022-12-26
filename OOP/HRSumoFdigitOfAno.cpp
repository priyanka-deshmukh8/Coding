#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int digit,temp,sum=0;
    temp=n;
    while(n>0)
    {
        sum+=(n%10);
        n=n/10;
    }
    cout<<"Sum = \t"<<sum;
    return 0;

}