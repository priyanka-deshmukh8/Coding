#include <iostream>

#define max 100000
using namespace std;

int main()
{

    unsigned int n, q, k;

    cin >> n >> q;
    int **a = new int *[max];
    for (int i = 0; i < n; i++)
        a[i] = new int[max];

    for (unsigned int i = 0; i < q; i++)
    {

        cin >> k;

        for (unsigned int j = 0; j < k; j++)
        {

            cin >> a[i][j];
        }
    }

    unsigned int u, v;
    for (unsigned int i = 0; i < q; i++)
    {
        cin >> u >> v;
        cout << a[u][v] << endl;
    }

    return 0;
}