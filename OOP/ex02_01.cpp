/* Write a function that takes the time as three integer arguments (hours, minutes and 
seconds) and returns the number of seconds since the last time the clock “struck 12.” Use 
this function to calculate the amount of time in seconds between two times, both of which 
are within one 12-hour cycle of the clock.*/

#include <iostream>
using namespace std;

int passedSeconds(int, int, int);
int difference(int, int, int);

int main()
{
    int hour1, minute1, second1;
    int hour2, minute2, second2;

    cout << "1. Enter hours, minutes and seconds (range 00:00:00 - 23:59:59): ";
    cin >> hour1 >> minute1 >> second1;

    if (hour1 > 23 || minute1 > 59 || second1 > 59)
    {
        if (hour1 < 23)
            cout << "\nEnter correct hours value!";
        if (minute1 < 59)
            cout << "\nEnter correct minutes value!";
        if (second1 < 59)
            cout << "\nEnter correct seconds value!";

        cout << "\n1. Enter hours, minutes and seconds: ";
        cin >> hour1 >> minute1 >> second1;
    }
    cout << "Passed seconds from last 12 (am or pm): " << passedSeconds(hour1, minute1, second1);

    cout << "\n2. Enter hours, minutes and seconds (range 00:00:00 - 23:59:59): ";
    cin >> hour2 >> minute2 >> second2;

    if (hour2 > 23 || minute2 > 59 || second2 > 59)
    {
        if (hour2 < 23)
            cout << "\nEnter correct hours value!";
        if (minute2 < 59)
            cout << "\nEnter correct minutes value!";
        if (second2 < 59)
            cout << "\nEnter correct seconds value!";

        cout << "\n2. Enter hours, minutes and seconds: ";
        cin >> hour2 >> minute2 >> second2;
    }
    cout << "\nDifference between two times is "
         << difference(hour2, minute2, second2) - difference(hour1, minute1, second1)
         << " seconds.";

    return 0;
}

int passedSeconds(int hour, int minute, int second)
{
    if (hour >= 12)
        hour -= 12;

    return hour * 60 * 60 + minute * 60 + second;
}

int difference(int hour, int minute, int second)
{
    return hour * 60 * 60 + minute * 60 + second;
}