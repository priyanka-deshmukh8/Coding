#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int units, cunits, punits;
    float bill;
    cout << "Enter the current reading=";
    cin >> cunits;
    cout << "Enter the previous  reading=";
    cin >> punits;
    units = cunits - punits;
    if (units < 300)
        bill = 3.0 * units;
    if (units > 300 && units <= 400)
        bill = ((3.5 * units) + (units * 0.5 / 100.0));
    if (units > 400 && units <= 500)
        bill = ((4.5 * units) + (units * 0.7 / 100.0));
    if (units > 500)
        bill = ((5.0 * units) + (units * 0.9 / 100.0));
    cout << "The electricity bill is=" << bill;
    return 0;
}