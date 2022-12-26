#include <bits/stdc++.h>
using namespace std;

void printDiamonds(int n)
{
    int space = n - 1;
    // Parent loop;
    for (int i = 0; i < n; i++)
    {
        // loop for initially print space before star printing
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }

        space--;
    }
}

int main()
{
    int row;
    cout << "Enter the rows   ";
    cin >> row;
    printDiamonds(row);
}