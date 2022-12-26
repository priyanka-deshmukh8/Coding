//////////////Orthogonal Check////////////
#include <iostream>
#define MAX 50
using namespace std;
bool isOrthogonal(int[][MAX], int);
void multiply(int[][MAX], int[][MAX], int[][MAX], int, int, int, int);
void transpose(int[][MAX], int, int, int[][MAX]);
int main()
{
    int a[MAX][MAX];
    int b[MAX][MAX];
    int p[MAX][MAX];
    int r1, c1, r2, c2;
    cout << " Enterr row(r1)" << endl;
    cin >> r1;
    cout << "Enter column(c1)" << endl;
    cin >> c1;

    for (int i = 0; i < r1; i++)
    {
        for (int k = 0; k < c1; k++)
        {
            cout << " Enter a[" << i << "][" << k << "]=" << endl;
            cin >> a[i][k];
        }
    }

    if (c1 != r1)
    {
        cout << "The given matrix can not be an Orthogonal Matrix";
        return 0;
    }
    transpose(a, r1, c1, b);
    for (int i = 0; i < r1; i++)
    {
        for (int k = 0; k < c2; k++)
        {
            cout << "b[" << i << "][" << k << "]=" << b[i][k] << "\t";
        }
        cout << "\n";
    }
    Multiply(a, b, p, r1, c1, r1, c1);
    for (int i = 0; i < r1; i++)
    {
        for (int k = 0; k < c2; k++)
        {
            cout << "p[" << i << "][" << k << "]=" << p[i][k] << "\t";
        }
        cout << "\n";
    }
    bool q;
    q = isOrthogonal(p, c1);
    if (q = 0)
    {
        cout << "The following matrix is orthogonal";
    }
    else
    {
        cout << "The following matrix is not orthogonal";
    }
    return 0;
}
void transpose(int a[][MAX], int r1, int c1, int b[][MAX])
{

    for (int i = 0; i < r1; i++)
    {
        for (int k = 0; k < c1; k++)
        {
            int t;
            t = a[i][k];
            b[k][i] = t;
        }
    }
}

void iply(int a[][MAX], int b[][MAX], int p[][MAX], int r1, int c1, int r2, int c2)
{

    for (int i = 0; i < r1; i++)
    {
        for (int m = 0; m < c2; m++)
        {
            p[i][m] = 0;
            for (int k = 0; k < r2; k++)
            {

                p[i][m] = p[i][m] + (a[i][k] * b[k][m]);
            }
        }
    }
}

bool isOrthogonal(int p[][MAX], int c1)
{
    for (int i = 0; i < c1; i++)
    {
        for (int k = 0; k < c1; k++)
        {
            if ((k != i) && (p[i][k] != 0))
                return 1;
            if ((k == i) && (p[i][k] != 1))
                return 1;
        }
    }
    return 0;
}