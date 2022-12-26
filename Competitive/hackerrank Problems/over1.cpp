#include<iostream>

using namespace std;

void repchar();
void repchar(char);
void repchar(char,int);

int main()
{
    repchar();
    repchar('$');
    repchar('*',30);
    return 0;
}
void repchar(char ch)
{
    for(int i=0;i<40;i++)
    {cout<<ch<<endl;}
}
void repchar(char ch,int n)
{
    for(int i=0;i<n;i++)
    {cout<<ch<<endl;}
}
