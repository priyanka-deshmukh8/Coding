#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    //1 4 6 2 8 9
    int p1; //2
    cin>>p1;

    v.erase(v.begin()+p1-1);

    //1 6 2 8 9 

    int x,y; //a=2 and b=4
    cin>>x>>y;

    v.erase(v.begin()+x-1,v.begin()+y-1);

    //1 8 9
    cout<<v.size()<<endl;
    for(int i:v)
    {
        cout<<i<<" ";
    }

    return 0;
}