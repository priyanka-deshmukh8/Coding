#include <iostream>

using namespace std;

class Complex
{
private:
    float real;
    float img;
    //real and img are member data or instance variable

public:
    //definition or implementation of function inside the class
    //such functions are treated as inline type
    Complex()
    {
        set(0, 0);
    }

    Complex(float r, float i)
    {
        set(r, i);
    }

    //only declaration, prototype or interface inside the class
    //such functions are treated as non-inline type
    void setReal(float r);
    float getReal() const; //const function will not permit change in member data
    void setImg(float i);
    float getImg() const; //const function will not permit change in member data
    void set(float r, float i);
    void show() const; //const function will not permit change in member data
    void read();
}; //end of class

//implementation or definition of member functions is out of the class
//by default these are non-inline type functions
void Complex::setReal(float r)
{
    real = r;
}

float Complex::getReal() const
{
    return real;
}

void Complex::setImg(float i)
{
    img = i;
}

float Complex::getImg() const
{
    return img;
}

void Complex::set(float r, float i)
{
    setReal(r);
    setImg(i);
}

void Complex::show() const
{
    cout << "real part: " << getReal() << " Imaginary part: " << getImg() << endl
         << endl;
}

void Complex::read()
{
    float r, i;
    cout << "Enter real part: ";
    cin >> r;
    cout << "Enter imaginary part: ";
    cin >> i;
    set(r, i);
}

int main()
{
    //Object or instance are being created; called instantiation
    //Complex c1; //default ctor is called
    Complex c1 = Complex(); //alternative way

    c1.show();
    c1.set(10.5F, 20.7F);
    c1.show();

    //Complex c2(100.34F, 200.566F); //parameterized ctor is called
    Complex c2 = Complex(100.34F, 200.566F); //alternative way

    c2.show();
    c2.set(1000, 2000);
    c2.show();

    return 0;
}