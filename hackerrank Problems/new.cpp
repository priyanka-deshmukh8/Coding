
#include <iostream>

using namespace std;

class Date
{
private:

    int dd,mm,yy;

public:


    Date(){set(1,1,2000);}
    Date(int d,int m,int y){set(d,m,s);}

    void setYear(int y)
    {yy= (1900<=y && y<=2100) ? y:2000;}

    int getYear()const
    {return yy;}

    void setMonth(int m)
    {mm = (1<=m && m<=12)?m:1;}

    int getMonth()const
    {return mm;}

    void setDay(int d)
    {
        int
        daysInMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

        int m = getMonth();
        if(m==2)//it is February
            dd = (1<=d && d<=28+isLeap())?d:1;

        else//it is not Feb
            dd = (1<=d && d<=daysInMonth[m])?d:1;
    }
    int getDay()const
    {return dd;}

    void show()const

    {
        cout<<getDay()<<":"<<getMonth()<<":"<<getYear()<<endl;
    }

    int isLeap()
    {
        int y;
        y= getYear();
        if((y %4==0 && y%100!=0)||(y%400==0))

            return 1;
        else
            return 0;
    }

    void nextDay()
    {
        setDay(getDay()+1);

        if(getDay()==1)
        {
            setMonth (getMonth()+1);
            if(getMonth()==1)
                setYear(getYear()+1);
        }
    }
    void addDays(int n)
    {
        for (int i=0;i<n;++i)
            nextDay();
    }


    ~Date()
    {cout<<"Destructor called"<<endl; }


};
int main()
{
    Date d1;
    d1.show();
    d1.set(31,12,2022);
    d1.show();
    d1.nextDay();
    d1.show();

    return 0;
}