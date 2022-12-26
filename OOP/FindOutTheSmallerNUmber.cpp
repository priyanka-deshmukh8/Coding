#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int a, b, c, min;
    cout << "Enter the value of a=";
    cin >> a;
    cout << "Enter the value of b=";
    cin >> b;
    cout << "Enter the value of c=";
    cin >> c;
    if (a < b)
        min = a;
    else
        min = b;
    if (c < min)
        min = c;
    cout << "The Smaller number is=" << min;
    return 0;
}