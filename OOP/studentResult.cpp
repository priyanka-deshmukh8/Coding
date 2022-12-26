#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int comp, phy, math, eng, chem, total;
    float avg;
    cout << "Enter the marks of Computer Science=";
    cin >> comp;
    cout << "Enter the marks of Physics=";
    cin >> phy;
    cout << "Enter the marks of Mathematics=";
    cin >> math;
    cout << "Enter the marks of English=";
    cin >> eng;
    cout << "Enter the marks of Chemistry=";
    cin >> chem;
    total = comp + phy + math + eng + chem;
    avg = ((total / 500.0) * 100.0);
    cout << "The total marks obtained by student=" << total << endl;
    cout<<"Percentage="<<avg<<endl;
    if (avg >= 85)
        cout << "Grade= A+";
    if (avg >= 75 && avg <= 84)
        cout << "Grade= A";
    if (avg >= 60 && avg <= 74)
        cout << "Grade= B";
    if (avg >= 50 && avg <= 59)
        cout << "Grade= C";
    if (avg < 50)
        cout << "Fail";

    return 0;
}