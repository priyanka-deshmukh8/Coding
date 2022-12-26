#include <iostream>
#include <stdio.h>

using namespace std;
int time(int x, int y, int z);
int main()
{
    int hor, min, sec;
    cout << "enter current time is hour minutes and second:::";
    scanf("%d%*c%d%*c%d", &hor, &min, &sec);
    if ((hor > 12) || (min > 60) || (sec > 60))
        cout << "enter valid time\n\n";
    else
        cout << "\n\ntotal amount of time in second::" << time(hor, min, sec) << "\n\n\n";
}
int time(int x, int y, int z)
{
    int sec;
    sec = x * 3600 + y * 60 + z;
    return sec;
}