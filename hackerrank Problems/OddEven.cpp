#include <iostream>
using namespace std;

int factorial(int n)
{
    int factorial=1;
    for (int i = 2; i <= n; i++)
    {
        factorial=factorial*i;
    }
    cout<<factorial<<endl;
    return factorial;
    
}

int main()
{
    int n,r;
    long ans;
    cout<<"Enter the number:"<<endl;
    cin>>n>>r;
    factorial(n);
    factorial(r);
    factorial(n*r);
    ans=factorial(n)*factorial(n-r);
    cout<<ans<<endl;


    return 0;
}