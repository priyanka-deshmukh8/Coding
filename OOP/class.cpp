#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

  class student //class definition begins
 {
 private:
     /* data */
     int rollno;
     char name[15];
     float marks;
     char grade;

 public:

     void getdata()
    {
        cout<<"Enter roll number of the students\n";
        cin>> rollno;
        cout<<"Enter name";
        gets(name);
        cout<<"\n Enter marks";
        cin>>marks;
    }
    void calcgrade()
    {
        if(marks>=90)
        grade='A';
        else if (marks>=75)
        grade='B';
        else if (marks<75)
        grade='C';
    }
    void display_data()
    {
        cout<<"\n Roll number is:\t"<<rollno;
        cout<<"\n Name is:\t"<<name;
        cout<<"\n Marks are:\t"<<marks;
        cout<<"\n Grade is is:\t"<<grade;
    }
};
int main()
{
    
    student s;
    s.getdata();
    s.calcgrade();
    s.display_data();
    getch();

    return 0;
}
 
 