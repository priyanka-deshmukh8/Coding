#include <iostream>
using namespace std;
class Time
{
private:
    int hour;
    int min;
    int sec;

public:
    Time(int = 0, int = 0, int = 0); //default ctor
    //setter function
    void setTime(int, int, int); //set hour,min and second
    void setHour(int);           //set hour
    void setMinutes(int);        //set minutes
    void setSecond(int);         //set second
    //getter function
    int getHour() const;   //return hour
    int getMinute() const; //return minute
    int getSecond() const; //return second

    void printUniversal(); //output universal time
    void printStandard();  //output standard time
};                         //end of class Time

