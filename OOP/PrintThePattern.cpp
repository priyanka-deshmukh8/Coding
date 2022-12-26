
#include<iostream>

using namespace std;

class Sample
{
    private:
    int *p;
    public:
    Sample(int x=0)
    {
        p=new int;
        *p=x;
    }
    void show()
    {
        cout<<*p<<" ";
        ~Sample();
        {
            delete p;
        }
    }
};
int main()
{
    Sample s1(10),s2;
    s2=s1;
    s1.show();
    s2.show();
    return 0;

}



