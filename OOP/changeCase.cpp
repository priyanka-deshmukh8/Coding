//Program to convert the lower and upeer to lower
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int n;
    char ch;
    cout << "Press any letterr either lower or upper case=";
    cin >> ch;
    n = ch;
    if (n >= 65 && n <= 90)
    {
        n = n + 32;
        ch = n;
        cout << "The lower case of your letter is=" << ch;
    }
    else if (n >= 96 && n <= 122)
    {
        n = n - 32;
        ch = n;
        cout << "The upper case ;of your letter is=" << ch;
    }
    else
        cout << "You Pressed a wrong letter";
}