#include <iostream>
#include <stdio.h>
using namespace std;
int duplicate(int a[], int x, int n);
int main()
{
    int n, p;
    cout << "enter current size:::";
    cin >> n;
    int a[n];
    int x;
    for (int i = 0; i < n; i++)
    {
        cout << "enter a element::";
        cin >> x;
        p = 1;
        while (p)
        {
            p = duplicate(a, x, i);

            if (p)
            {
                cout << "not permittend::";
                cout << "enter a number::";
                scanf("%d", &x);
            }
        }
        a[i] = x;
    }
    int i;
    for (i = 0; i < n; i++)
        cout << "\n"
             << a[i];
}
int duplicate(int a[], int x, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (x == a[i])
            return 1;
    }
    return 0;
}