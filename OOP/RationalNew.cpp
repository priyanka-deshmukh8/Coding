#include <iostream>
using namespace std;
class Rational
{
private:
    int num;
    int den;

public:
    Rational() : num(0), den(1)
    {
    }
    Rational(int x, int y)
    {
        set(x, y);
    }
    void set_num(int x)
    {
        num = x;
    }
    void set_den(int y)
    {
        den = (y > 0) ? y : 1;
    }
    void set(int x, int y)
    {
        set_num(x);
        set_den(y);
    }
    int get_num(void)
    {
        return num;
    }
    int get_den(void)
    {
        return den;
    }
    void Addition(Rational c1, Rational c2);
    void Subtraction(Rational c1, Rational c2);
    void multiplication(Rational c1, Rational c2);
    void Divition(Rational c1, Rational c2);
    void show(void)
    {

        cout << get_num() << "/" << get_den() << "=" << (float)get_num() / get_den() << endl;
    }
};
void Rational::Addition(Rational c1, Rational c2)
{

    set_num(c2.get_num() * c2.get_den() + c2.get_num() * c1.get_den());
    set_den(c1.get_den() * c2.get_den());
}

void Rational::Subtraction(Rational c1, Rational c2)

{
    set_num((c1.get_num() * c2.get_den()) - (c2.get_num() * c1.get_den()));
    set_den(c1.get_den() * c2.get_den());
}

void Rational::multiplication(Rational c1, Rational c2)

{
    set_num(c1.get_num() * c2.get_num());
    set_den(c1.get_den() * c2.get_den());
}

void Rational::Divition(Rational c1, Rational c2)

{
    set_num(c1.get_num() * c2.get_den());
    set_den(c1.get_den() * c2.get_num());
}

int main()
{
    Rational c1(1, 2), c2(1, 2), c3, c4, c5, c6;
    c1.show();
    c2.show();
    c3.Addition(c1, c2);
    c3.show();
    c4.Subtraction(c1, c2);
    c4.show();
    c5.multiplication(c1, c2);
    c5.show();
    c6.Divition(c1, c2);
    c6.show();
}