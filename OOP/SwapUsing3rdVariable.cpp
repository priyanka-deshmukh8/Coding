#include <iostream>

using namespace std;

int main()
{
    int num1, num2, temp;

    cout << "Enter 2 numbers:\n";
    cin >> num1 >> num2;
    cout << "\nBefore Swap :  num1=" << num1 <<"\tnum2="<< num2;

    //swpping logic
    temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "\nAfter Swap  :  num1=" << num1 <<"\tnum2="<< num2;

    return 0;
}