#include<bits/stdc++.h>
#include<deque>

using namespace std;

int main()
{
    int n,k, test;
    cin>>test;
    while (test--)
    {
        cin>>n>>k;
        int a;
        deque<int>arr;

        for(int i=0;i<n;i++)
        {
            cin>>a;
            arr.push_back(a);
        }
        for(int i=0;i<k;i++)
        {
            arr.push_front(arr.back())
            arr.pop_back();
        }
        deque <int> ::iterator itrtr;
        for(itrtr=arr.begin();itrtr!=arr.end();++itrtr)
        cout<<*itrtr<<" ";
    }
    
}