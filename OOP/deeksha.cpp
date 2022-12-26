#include <iostream>

using namespace std;

class Complex
{
private:
    float real;
    float img;

public:
    void setReal(float r)
    {
        real = r;
    }
    float getReal() //parenthesis
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

    void set(float r, float i)
    {
        setReal(r);
        setImg(i);
    }

    void show()
    {
        cout << "real part:" << getReal() << "\t"
             << "Imaginary part:" << getImg() << endl;
    }
};
int main()
{
    Complex c1;
    c1.set(10, 20);
    c1.show(); //every statement should terminated by a semicolon

    return 0;

} //semicolon is used to terminate only definition of class and  structure type functions
