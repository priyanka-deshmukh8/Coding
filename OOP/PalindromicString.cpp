#include<iostream>

using namespace std;


int main()
{
    bool b=true;
    string s;
    cin>>s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            cout << "NO";
            b = false;
            break;
        }
    }
    if (b)
    {
        cout << "Yes";
    }
}