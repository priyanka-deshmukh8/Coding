#include<stdio.h>

int main()
{
    int m,k;
    m=((k=5)+(k=8)+(k=9)+(k=7));
    printf("m=%d\n",m);
    printf("k=%d\n",k);
    return 0;
}
/*There is an ambiguity in the C compiler
According to ques ambiguity is with the grouping  operator or parenthesis.
whenever  there is an expression compiler internally solves with the grouping method
Grouping Method means compiler gives higher priority to the parenthesis
                      m=(k=5)+(k=8)+(k=9)+(k=7);
WKT  parenthesis associativity is left to right 
m=Expression 1+Expression 2+Expression 3 + Expression 4;
again next is + has higher priority 
which need 2operands to perform  the operation and associativity is left to right.
so */
