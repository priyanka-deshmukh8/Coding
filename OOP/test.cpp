
#include <iostream>
using namespace std;
class Test
{
    private:
    int x;
    public:
    void setX(int x)
    {x=x;}
    void print(){cout<<x<<endl;}
};


int main() {
    // Write C++ code here
 Test obj;
   obj.setX(10);
   obj.print();
   

    return 0;
}