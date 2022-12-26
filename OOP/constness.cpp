#include<iostream>
 
int main()
{
    int x0=0,x1=10,x2=20,x3=30;

    int* p0;
    const int* p1;
    //int* const p2;
   // const int* const p3;

    p0=&x0;
    p1=&x1;
   // p2=&x2;
   // p3=&x3;

    //Behavior of p0
    (*p0)++;
    p0++;
    
    //Behavior of p1
    //(*p1)++; //error:change not permitted
    p1++;

    //Behavior of p2
    //(*p2)++;
    //p2++;

    ////Behavior of p3
   // (*p3)++;
    //p3++;



}