#include <iostream>
using namespace std;

struct student
{    
    char name[50];
    char roll[10];
    float marks[5];
};

int main() 
{
    student s;
    cout << "Enter information," << endl;
    cout << "Enter name: ";
     gets(s.name);
    cout << "Enter roll number: ";
    cin >> s.roll;
    cout << "Enter marks: ";
    for(int i=0;i<5;i++)
    cin >>s.marks[i];

    cout << "\nDisplaying Information," << endl;
    cout << "Name: " << s.name << endl;
    cout << "Roll No. : " << s.roll << endl;
    for(int i=0;i<5;i++)
    cout << "Marks: " << s.marks[i] << endl;
    return 0;
}