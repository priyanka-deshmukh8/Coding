#include<iostream>
using namespace std;

int main()
{
    char *pc;
    int *pi;
    double *pd;

    char c='a';
    int i=20;
    double d=3.14;

    cout<<sizeof(pc)<<sizeof(pi)<<sizeof(pd)<<endl;
    cout<<sizeof(c)<<sizeof(i)<<sizeof(d)<<endl;
    
    pc=&c;
    pi=&i;
    pd=&d;

    cout<<pc<<pi<<pd<<endl;

    ++pc;
    ++pi;
    ++pd;

    cout<<pc<<pi<<pd<<endl;
    cout<<*pc<<*pi<<*pd<<endl;
    return 0;
}