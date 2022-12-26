#include <iostream>

using namespace std;

bool isPerfect(int n);
void printPerfect(int n);

int main()
{
    int n;

    cout<<"Enter a count: ";
    cin>>n;
    printPerfect(n);

    return 0;
}

void printPerfect(int n)
{
    for (int i=1; i<=n; ++i)
    {
        if (isPerfect(i))
            cout << i << "\t";
    }

    cout <<endl;
}

bool isPerfect(int x)
{
    int sum = 0;

    for (int i=1; i<=x/2; ++i)
    {
        if (x%i==0)
            sum += i;
    }
    return (x==sum);
}