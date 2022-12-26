#include<bits/stdc++.h>

using namespace std;
int  main()
{
    string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char mp[26];
    int k =26;
    int hash =18;
    int j=100;
    for(int i=0;i<k;i++)
    {
        mp[i]=((((s[i]-'A'))+(i+j)%hash)+'A');
        j=j-hash;
        if(j<=0)
        {
            j=100;
        }
    }
    int mp1[26]={0};
    for(int i=0;i<26;i++)
    {
        mp1[mp[i]-'A']++;
    }
    int res=mp1[16];
    cout<<(char)(s[0]+res)<<(char)(s[25]-res)<<endl;
}