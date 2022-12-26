#include <iostream>

using namespace std;

class Complex
{
private:
    float real;
    float img;
    //real and img are member data or instance variable

public:
    //default constructor
    Complex()
    {
        set(0, 0);
    }

    Complex(float r, float i) //parameterized constructor
    {
        set(r, i);
    }

    void setReal(float r)
    {
        real = r;
    }
    float getReal()
    {
        return real;
    }
    void setImg(float i)
    {
        img = i;
    }
    float getImg()
    {
        return img;
    }

    void set(float r, float i) //function to assign value to real part and imaginary part
    {
        setReal(r);
        setImg(i);
    }

    void show()
    {
        cout<<"real part: "<< getReal()<<" Imaginary part: "<<getImg()<<endl<<endl;
    }


    void read()
    {
        float r, i;
        cout<<"Enter real part: "; cin>>r;
        cout<<"Enter imaginary part: "; cin>>i;
        set(r, i);
    }
};

int main()
{
    Complex c1; //default ctor is called implicitly

    c1.show();
    c1.set(10, 20);
    c1.show();

    Complex c2(100, 200); //parameterized ctor is called implicitly
    c2.show();
    c2.set(1000, 2000);
    c2.show();

    return 0;
}