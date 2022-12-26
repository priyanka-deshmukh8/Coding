#include <iostream>
using namespace std;

int c_f(int);
int f_c(int);

int main()
{
    int temp,choice;


    cout << "Enter 1 : Fahrenheit to celcius \nEnter 2 : Celcius to Fahrenheit" << endl;
    cin >> choice;
    cout << endl;

    if (choice == 1)
    {

        cout << "FAHRENHEIT\t\t\tCELSIUS\n";
        cout << "_______________________________________\n";
        for (int temp = 32; temp < 212; temp++)
        {

            cout << temp << "\t\t\t" << f_c(temp) << endl;
            cout << "___________________|____________________|\n";
        }
    }

    else if (choice == 2)
    {
        cout << "CELSIUS\t\t\tFAHRENHEIT" << endl;
        for (int temp = 0; temp < 100; temp++)
        {

            cout << temp << "\t\t\t" << c_f(temp) << endl;
            cout << "___________________|____________________|\n";
        }
    }

    else
    {
        cout << "Please enter a valid input" << endl;
    }

    return 0;
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