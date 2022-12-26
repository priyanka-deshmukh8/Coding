#include<iostream>
#include<conio.h>
#include<stdlib.h>

class Clock
{
    int hrs,min,sec;
    public:
    Clock()   //default constructor
    {
        hrs=min=sec=0;
    }
    Clock(int h,int m,int s) //parameterised constructor
    {
        hrs=s;min=m;sec=s;
    }
    void ReadTime();
    void ShowTime24();
    void ShowTime12();
    

}