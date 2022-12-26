#include <iostream>

using namespace std;

class Date
{
private:
    int dd, mm, yy;

public:
    Date():dd(1), mm(1), yy(2000)
    {}
    Date(int d, int m, int y)
    {set(d, m, y);}

    void setDay(int d)          //to perform operation on data
    {
        int daysInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

        if (getMonth() != 2) //it is not Feb
            dd = (1<=d && d<=daysInMonth[mm]) ? d : 1;
        else    //it is Feb, need to check for leap year
            dd = (1<=d && d<=28+isLeap() )? d : 1;
    }
    int getDay() const  //to  get data and return to perform operations to another function
    {return dd;}

    void setMonth(int m)         
    {mm = (1<=m && m<=12)? m : 1;}
    int getMonth() const
    {return mm;}

    void setYear(int y)
    {yy = (1900<=y && y<=2100)  ? y : 2000;}
    int getYear() const
    {return yy;}

    //Member functions declared here but defined out of the class
    void set(int d, int m, int y);         //
    void show() const;
    int isLeap() const;
    void read();
    void nextDay();
    void addDays(int n);
};

//Member functions defined out of the class
void Date::set(int d, int m, int y)     
{
    setYear(y);  
    setMonth(m);
    setDay(d);
}
void Date::show() const
{cout<<"Date is: "<<getDay()<<":"<<getMonth()<<":"<<getYear()<<endl;}

int Date::isLeap() const
{
    if (( yy%4==0 && yy%100 != 0) || (yy%400==0))
        return 1;
    else
        return 0;
}

void Date::read()  //to get input from  user
{
    int d, m, y;
    cout<<"Enter day: "; cin>>d;
    cout<<"Enter month: "; cin>>m;
    cout<<"Enter year: "; cin>>y;
    set(d, m, y);
}

void Date::nextDay()   //promote invalid date to next day/month or year
{
    setDay(getDay()+1);
    if (getDay() == 1)
    {
        setMonth(getMonth()+1);
        if (getMonth() ==1)
            setYear(getYear()+1);
    }
}

void Date::addDays(int n)
{
    for (int i=0; i<n; ++i)
        nextDay();
}

int main()
{
    Date d;

    d.show();
    d.set(30, 4, 2021);
    d.show();

    d.nextDay();
    d.show();

    d.addDays(100);
    d.show();

    return 0;
}