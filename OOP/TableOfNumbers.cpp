#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int sum, counter, n;
    cout << "Enter the number of tables=";
    cin >> n;
    counter = 1;
in: //label
    sum = n * counter;
    cout << n << "*" << counter << "=" << sum << endl;
    counter = counter + 1;
    if (counter <= 10)
        goto in;
    return 0;
}