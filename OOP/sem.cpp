#include<iostream>
using namespace std;

template<class T>class Sample{
    public:
    T fun(T x);

     

};
template <T>T sample<T>::fun(T x)
{
    cout<<"T is an integer"<<endl;
    return x;
}
int main()
{
    sample <int>s;
    cout<<s.fun(10);
    return 
}