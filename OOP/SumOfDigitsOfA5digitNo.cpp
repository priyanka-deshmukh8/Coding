#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int n,sum;
    cout<<"Enter a number:"<<endl;
    cin>>n;
    while (n>0)
    {
        sum+=(n%10);
        n=n/10;
    }
    cout<<"\n"<<sum;
    

    return 0;
}