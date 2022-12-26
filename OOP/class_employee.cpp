/* consider the class Employee with the following specification:
private data members:
empno           integer
empname         string with 25 characters
desig           string with 20 characters
salary          float data type
public member functions:
function        getdata()
function        dispdata()

*/

#include <iostream>
#include <conio.h>

using namespace std;

class Employee
{
private:
    int empno;
    char empname[25];
    char desig[20];
    float salary;

public:
    void getdata() //to fetch the values for data members of class employee
    {
        cout << "Enter employee number\n";
        cin >> empno;
        cout << "Enter Employee name:\n";
        gets(empname);
        cout << "Enter the designation:";
        gets(desig);
        cout << "Enter the salary:";
        cin >> salary;
    }
    //to display the values of private data members of class employee
    void dispdata()
    {
        cout <<endl<< "Employee number\t"<<empno;

        cout <<endl<< "Employee name:\t"<<empname;

        cout <<endl<< "Designation:\t"<<desig;

        cout <<endl<< "Salary:\t"<<salary;
    }
}; //class definition over
int main()
{
    Employee e;
    e.getdata();  //member function calls to input
    cout<<"******************Employee Details***********************";
    e.dispdata(); //and display the employee details
 return 0;
}
