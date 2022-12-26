#include <iostream>
using namespace std;

int c_f(int);
int f_c(int);

int main()
{
    cout <<endl<<endl;
    cout << "          CELSIUS         " <<endl << endl <<endl;
    for (int i = 0; i <= 100; i++)
    {
        cout << i <<" Celsius = " << c_f(i) << " Farenhiet" << endl;
    }

    cout <<endl<<endl;
    cout << "         FARENHIET         " <<endl << endl <<endl;
    for (int i = 0; i <= 212; i++)
    {
        cout << i <<" Farenhiet = " << f_c(i) << " Celsius" << endl;
    }
    

    
}
int c_f(int celsius)
{
    int fahrenheit = (celsius * 9.0) / 5.0 + 32;
    return fahrenheit;
}
int f_c(int fahrenheit)
{
    int celsius = 5.0 * (fahrenheit - 32) / 9.0;
    return celsius;
}
