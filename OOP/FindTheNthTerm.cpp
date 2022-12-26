#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

//complete the following function

int Find_nth_Term(int n ,int a ,int b ,int c)
{
    //write your code here
    if(n==1)
    return a;
    else if(n==2)
    return b;
    else if (n==3)
    return c;
    
    return Find_nth_Term (n-1,a,b,c)+ Find_nth_Term(n-2,a,b,c)+Find_nth_Term(n-3,a,b,c);
}
int main()
{
    int n,a,b,c;

    scanf("%d %d %d %d",&n,&a, &b, &c);
    int ans=Find_nth_Term(n,a,b,c);

    printf("%d",ans);
    return 0;
}