//program to find out the day of given date starting from jan 2001
//This code is Contributed by Priyanka Deshmukh
#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
    int d, m, y;
    int n = 0;
    int ly = 0;
    int td, r, i, j, ny;
    cout << "Enter the day dd(01)=";
    cin >> d;
    cout << "Enter the Month mm(01)=";
    cin >> m;
    cout << "Enter the year yy from(2001)=";
    cin >> y;
    for (i = 1; i < m; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            n = n + 31;
        else if (i == 2 && y % 4 != 0)
            n = n + 28;
        else if (i == 2 && y % 4 == 0)
            n = n + 29;
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            n = n + 30;
    }
    for (j = 2001; j < y; j++)
    {
        if (j % 4 == 0)
            ly = ly + 1;
    }
    ny = (y - 2000) - 1; //ny=(2021-2000)-1                     : 20
    td = ly + n + d + (ny * 365); //td= 0+31+26+(20 * 365) =7357
    r = td % 7; 
    switch (r)
    {
    case 0:
        cout << "The day is Sunday";
        break;
    case 1:
        cout << "The day is Monday";
        break;
    case 2:
        cout << "The day is Tuesday";
        break;
    case 3:
        cout << "The day is Wednesday";
        break;
    case 4:
        cout << "The day is Thursday";
        break;
    case 5:
        cout << "The day is Friday";
        break;
    case 6:
        cout << "The day is Saturday";
        break;
    }
    getch();
}
