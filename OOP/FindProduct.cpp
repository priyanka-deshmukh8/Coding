#include<iostream>

using namespace std;

int main()
{
    int n,a;
    long long int pro=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        pro=(long long int)((pro*a) % (1000000007));
    }
    cout<<pro;
    return 0;
}