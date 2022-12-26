#include<iostream>

using namespace std;

int main()
{
    int x;
    int *px;
    x=10;
    px=&x;
    cout<<x<<*px<<endl;
    ++x;
    ++(*px);
    cout<<x<<*px<<endl;
    return 0;
}