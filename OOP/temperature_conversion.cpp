#include<iostream>
#include<conio.h>
 
using namespace std;


int main()
{
    
    float ftemp,ctemp; //declare float variable
    cout<<"Enter the temperature in fahrenheit=";
    cin>>ftemp;
    ctemp=((ftemp-32.0)*5.0/9.0);
    cout<<"The centegrade temperature is ="<<ctemp;
     
     return 0;
}



