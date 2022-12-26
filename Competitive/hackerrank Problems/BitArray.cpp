#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
    unsigned long long  n,s,p,q,r=0,ans=0,a,v;
    n=1e8; s,p,q,v=pow(2,31) ;
    cin>>n>>s>>p>>q;
    unsigned long long i,m,m0,o,t0,t;
    m=s;n=s;o=0;p=0;
    for(i=0;i<n;i++)
    {
        m=(m*p+t);
        m=m%v;
        if((m==m0|| m==o) && i!=0)
        {
            t0=i+1;
            break;
        }
        o=m;
    }
    if(i==n) 
    t0=i;

cout<<t0;
return 0;

}