#include <iostream>
#include<string.h>

using namespace std;

int main()
{
    int n;
    char* a[10] = {"Greater than 9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> n;

    if (n > 9)
        puts(a[0]);
    else
        puts(a[n]);

    return 0;
}