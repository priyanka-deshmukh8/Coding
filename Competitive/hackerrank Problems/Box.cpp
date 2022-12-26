#include<iostream>

using namespace std;

class Box
{
    private:
    int l,b,h;
    public:
    Box(int length,int breadth,int height):l(length),b(breadth),h(height){BoxesCreated++}

};