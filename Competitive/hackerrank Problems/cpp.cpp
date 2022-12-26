#include <iostream>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    int** s = new int* [n];

    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        int *b=new int [a];
        for (int j = 0; j < a; j++)
        {
            int e;
            cin>>e;
            b[j]=e;
        }
        *(s+i)=b;
    }

    
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << s[u][v] << endl;
    }
    return 0;
}