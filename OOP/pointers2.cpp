//incrlnPtr.cpp:increment in pointer and size of pointer
#include<stdio.h>

using namespace std;

int main()
{
    char *pc;
    int *pi;
    double *pd;
    char c='a';
    int i=20;
    double d=3.14;

    printf("\n%d%d%d",sizeof(pc),sizeof(pi),sizeof(pd));
    
    return 0;

}