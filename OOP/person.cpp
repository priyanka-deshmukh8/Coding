#include <iostream>

using namespace std;

class Person               //class of persons
{
    char name[40];        //person's name 
    int age;              //person's age

public:
    void setData() //set the name and age
    {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter age:";
        cin >> age;
    }
    void printData() //display the name and age
    {
        cout << "\nName:" << name
             << "Age:" << age;
    }
};
int main()
{
    Person *persPtr[10];
    int n = 0;
    char choice;
    do
    {
        persPtr[n] = new Person;
        persPtr[n]->setData();
        n++;
    }while(n!=0);
    for(int j=0;j<n;j++)//print names and age of all persons
    {
        cout<<"\n\nPerson number"<<j+1;
        persPtr[j]->printData();
    }
    for(int j=0;j<n;j++)
      delete persPtr[j];
    cout<<endl;
    return 0;
}