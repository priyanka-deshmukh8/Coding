#include <iostream>
using namespace std;
/* (0+0)=0,
(1+0)=1,
 (1+1)=0 and 1 will be carry over.*/
void AddTwoBinary(int a, int b)
{
    int sum[15], remainder = 0, i = 0;
    while (a != 0 || b != 0)
    {
        sum[i++] = (a % 10 + b % 10 + remainder) % 2;
        remainder = (a % 10 + b % 10 + remainder) / 2;
        a = a / 10;
        b = b / 10;
    }
    if (remainder != 0)
        sum[i++] = remainder;
    --i;
    cout<<"Sum of two binary numbers: ";
    while (i >= 0)
        cout<<sum[i--];
    
}

int main()
{
    int a, b;

    cin >> a >> b;
    AddTwoBinary(a, b);

    return 0;
}