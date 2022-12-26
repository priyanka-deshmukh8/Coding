#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    const int N = 1e2 + 2;
    int idx[N];
    for (int i = 0; i < N; i++) //to initialize all element as -1
    {
        idx[i] = -1;
    }
    int minidx = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] != -1)
        {
            minidx = min(minidx, idx[arr[i]]);
        }
        else
        {
            idx[arr[i]] = i;
        }
    }
    if (minidx == INT_MAX)
    {
        return -1;
    }
    else
    {
        cout << minidx + 1;
    }

    return 0;
}