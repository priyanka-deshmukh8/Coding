#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int marks;
    cout << "Enter the marks=";
    cin >> marks;
    if (marks >= 85)
        cout << "The Grade is A1";
    else if (marks >= 80)
        cout << "The Grade is A2";
    else if (marks >= 75)
        cout << "The Grade is B1";
    else if (marks >= 70)
        cout << "The Grade is B2";
    else if (marks >= 60)
        cout << "The Grade is C";
    else if (marks >= 50)
        cout << "The Grade is D";
    else
        cout << "The Grade is F";
}