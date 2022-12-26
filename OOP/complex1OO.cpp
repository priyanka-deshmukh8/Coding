#include <iostream>

using namespace std;

class Complex
{
    private:
    float real,img;
    public:
    //constructor
    Complex(float r=0.0,float i=0.0)
    { real=r;   img=i;}
    
    //setter  function
    void set(float r=0.0,float i=0.0)
    {real=r;    img=i;}

    //display function
    void display(void)
    {
        cout << "real:  "<< real<<"imaginary:   "<<img<< endl;
    }
    //prototype of +operator overloaded
    Complex operator+(Complex c2);
    //definition outside the class
    Complex Complex::operator+(Complex c2)
    {
        Complex temp;
        temp.real=real+c2.real;//add real part
        temp.img=img+c2.img;
        return temp;
        //return resultant object
    }
};
int main()
{
    Complex c1(4,5.2),c2,c3;
    c2.set(7,4.9);
    c3=c1+c2;
    //the enlarged call: c3=c1.operator+(c2);
    c3.display();
    return 0;
}