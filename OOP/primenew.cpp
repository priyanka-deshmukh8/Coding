#include <iostream>
using namespace std;
int prime(int x);

int main()
{
    int x;
    int flag;
    
    cout << "Enter any number: ";
    cin >> x;

    flag = prime(x);
    if (flag == 1)
        cout << x << " is a prime number";
    else
        cout << x << " is not a prime number";
    return 0;
}
int prime(int x)
{
    int flag = 1;
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}