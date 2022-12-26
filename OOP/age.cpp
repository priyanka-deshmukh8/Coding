//Program to calculate age of human by entering DOB or timeInterval(in yymmdd) b/w two dates
#include <iostream>
#include <conio.h>

using namespace std;
 
int main()
{
    int dd,mm,yy,dd1,mm1,yy1;
    int d,m,y;
    int dd2,mm2,yy2;
    cout<<"\t\tThis code is contributed by Priyanka Deshmukh\t\t\n";
    cout<<"Enter the  current day=";
    cin>>dd;
    cout<<"Enter the current month=";
    cin>>mm;
    cout<<"Enter the current year=";
    cin>>yy;
    cout<<"Enter the previous day=";
    cin>>dd1;
    cout<<"Enter the previous month=";
    cin>>mm1;
    cout<<"Enter the previous year=";
    cin>>yy1;
    if(dd1<=dd&&mm1<=mm||yy1<=yy)
    {
        d=dd-dd1;
        m=mm-mm1;
        y=yy-yy1;
    } 
   
    if(dd1<=dd && mm1>mm&&yy1<yy)
    {
        d=dd-dd1;
        mm2=mm+12;
        m=mm2-mm1;
        y=yy-yy1-1;
    }
    if (dd1>dd && mm1<mm && yy1<yy)
    {
        if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
        {
            dd2=dd+31;
            d=dd2-dd1;
            m=mm-mm1-1;
            y=yy-yy1;
        }
        if(mm==2 && yy%4==0)
        {
            dd2=dd+29;
            d=dd2-dd1;
            m=mm-mm1-1;
            y=yy-yy1;
        }
        if(mm==2&&yy%4!=0)
        {
            dd2=dd+28;
            d=dd2-dd1;
            m=mm-mm1-1;
            y=yy-yy1;
        }
        if(mm==4||mm==6||mm==9||mm==11)
        {
            dd2=dd+30;
            d=dd2-dd1;
            m=mm-mm1-1;
            y=yy-yy1;
        }
    }
    if(dd1>dd&&mm1>=mm&&yy1<yy)
    {
        if (mm==1||mm==3||mm==5||mm==8||mm==10||mm==12)
        {
            dd2=dd+31;
            dd=dd2-dd1;
            mm2=mm+12-1;
            m=mm2-mm1;
            y=yy-yy1-1;
        }
        if(mm==2&&yy%4==0)
        {
            dd2=dd+29;
            d=dd2-dd1;
            mm2=mm+12-1;
            m=mm2-mm1;
            y=yy-yy1-1;
        }
        if(mm==2 && yy%4!=0)
        {
            dd2=dd+28;
            d=dd2-dd1;
            mm2=mm+12-1;
            m=mm2-mm1;
            y=yy-yy1-1;
        }
        if(mm==4||mm==6||mm==9||mm==11)
        {
            dd2=dd+30;
            d=dd2-dd1;
            mm2=mm+12-1;
            m=mm2-mm1;
            y=yy-yy1-1;
        }
    }
    
    cout<<"The days are ="<<d<<endl;
    cout<<"The months are ="<<m<<endl;
    cout<<"The years are ="<<y<<endl;
    getch();
}

        

    



    

