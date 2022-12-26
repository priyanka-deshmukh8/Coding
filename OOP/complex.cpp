
#include <iostream>

using namespace std;

class Complex
{
private:
    float real, img;

public:
    Complex():real(0), img(0)
    {}

    Complex(float r, float i)
    {set(r, i);}

    void setReal(float r);
    float getReal() const;
    void setImg(float i);
    float getImg() const;
    void set(float r, float i);
    void show() const;
    void read();

    Complex add(Complex c2) const ;
    Complex multiply(Complex c2);
}; //end of class

Complex Complex::multiply(Complex c2)
{
    Complex temp;


    return temp;
}

Complex Complex::add(Complex c2) const
{
    Complex temp;

    temp.setReal(getReal() + c2.getReal()); //temp.real = real + c2.real;
    temp.setImg(getImg() + c2.getImg());    //temp.img = img + c2.img;

    return temp;
}

void Complex::setReal(float r)
{real = r;}

float Complex::getReal() const
{return real;}

void Complex::setImg(float i)
{img = i;}

float Complex::getImg() const
{return img;}

void Complex::set(float r, float i)
{setReal(r); setImg(i);}

void Complex::show() const
{cout<<"real part: "<< getReal()<<" Imaginary part: "<<getImg()<<endl<<endl;}

void Complex::read()
{
    float r, i;
    cout<<"Enter real part: "; cin>>r;
    cout<<"Enter imaginary part: "; cin>>i;
    set(r, i);
}

//non-member or free function
Complex subtract(Complex c1, Complex c2)
{
    Complex temp;

    temp.setReal(c1.getReal() - c2.getReal()); //temp.real = c1.real - c2.real;
    temp.setImg(c1.getImg() - c2.getImg());    //temp.img = c1.img - c2.img;

    return temp;
}


int main()
{
    Complex c1, c2, c3, c4, c5;

    c1.set(10, 20);
    c2.set(100, 200);

    c1.show();  //current object is c1
    c2.show();  //current object is c2

    c3 = c1.add(c2); //current object is c1
    c3.show();  //current object is c3

    c4 = subtract(c1, c2);  //c4 = c1- c2;
    c4.show();

    (c1, c2);  //c5 = c1* c2;
    c5.show();

    return 0;
}
