#include <iostream>
using namespace std;
class Calculate //class definition begins
{
    int num1; //Data members of class
    int num2;
    int result;

public:
    void add() //Member function definition
    {
        cout << "Enter two numbers:\n";
        cin >> num1 >> num2;
        result = num1 + num2;
        cout << "\n Addition of two numbers is:" << result;
    }
    void subtract()
    {
        cout << "\nEnter two numbers: " << endl;
        cin >> num1 >> num2;
        result = abs(num1 - num2);
        cout << "\n Difference of two numbers is:" << result;
    }
    void multiply()
    {
        cout << "\nEnter two numbers: " << endl;
        cin >> num1 >> num2;
        result = num1*num2;
        cout << "\n Multiplication  of two numbers is:" << result;
    }
    void divide()
    {
        cout << "\nEnter two numbers: " << endl;
        cin >> num1 >> num2;
        result = num1/num2;
        cout << "\n Multiplication  of two numbers is:" << result;
    }

}; //class definition over
int main()
{
    Calculate calc;
    calc.add();
    calc.subtract();
    calc.multiply();
    calc.divide();
    return 0;
}
