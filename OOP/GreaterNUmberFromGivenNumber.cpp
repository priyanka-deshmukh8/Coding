#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int a, b, c, max;
    cout << "Enter the value of a=";
    cin >> a;
    cout << "Enter the value of b=";
    cin >> b;
    cout << "Enter the value of c=";
    cin >> c;
    if (a > b)
        max = a;
    else
        max = b;
    if (c > max)
        max = c;
    cout << "The Greater number is=" << max;
    return 0;
}