#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int img;

public:
    Complex() : Complex(0, 0) {}
    Complex(int x, int y)
    {
        set(x, y);
    }
    void set_real(int x)
    {
        real = x;
    }
    void set_img(int y)
    {
        img = y;
    }
    void set(int x, int y)

    {
        set_real(x);
        set_img(y);
    }
    int get_real(void) const
    {
        return real;
    }
    int get_img(void) const
    {
        return img;
    }

    void read();
    Complex operator+(const Complex &c2) const;
    Complex operator-(const Complex &c2) const;
};

Complex Complex::operator+(const Complex &c2) const
{
    Complex temp;
    temp.set_real(get_real() + c2.get_real());
    temp.set_img(get_img() + c2.get_img());
    return temp;
}
Complex Complex::operator-(const Complex &c2) const
{
    Complex temp;
    temp.set_real(get_real() - c2.get_real());
    temp.set_img(get_img() - c2.get_img());
    return temp;
}

void operator>>(istream &is, Complex &c)

{
    int x, y;
    cout << "\nenter real part  ::";
    cin >> x;
    cout << "\nenter img part  ::";
    cin >> y;
    c.set(x, y);
}

void operator<<(ostream &i, const Complex &c)

{
    cout << "\n\n complex number==" << c.get_real() << "+i" << c.get_img();
}
int main()
{
    Complex c1, c2, c3, c4;

    cin >> c1;

    cout << endl;
    cin >> c2;

    c3 = c1 + c2;
    c4 = c1 - c2;

    cout << c3;

    cout << endl;
    cout << c4;
    cout << endl;
}