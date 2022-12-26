#include <iostream>
#include <string.h>

using namespace std;

bool check(string str)
{
    int n = str.length();

    int count = 0;

    for (int i = 0; i < n / 2; ++i)

        if (str[i] != str[n - i - 1])

            ++count;

    return (count <= 1);
}

int main()
{
    string str;
    string atr;
    cout << " enter string ";
    cin >> str;
    int count = 0;
    /*if(	check(str))
    count++;*/

    int n = str.length();
    atr = str;
    for (int i = 0; i < n; i++)
    {
        str = atr;
        char x, y;
        x = str[i];
        for (int j = i + 1; j < n; j++)
        {
            y = str[j];
            str[j] = x;
            str[i] = y;
            cout << str << endl;

            if (check(str))
                count++;
            str = atr;
        }
    }

    cout << count;
}