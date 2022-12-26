#include <iostream>
#include <math.h>
using namespace std;
class Student
{
private:
    string s_name;
    string reg_no;
    int marks[6];
    int total;
    float avg;
    float st;
    char grade;
    //float std,avg;
public:
    Student()
    {
        avg = 0;
    }
    void setName(string name)
    {
        s_name = name;
    }
    void setReg(string reg)
    {
        reg_no = reg;
    }
    void setMarks(int a[])
    {
        int t = 0;
        for (int i = 0; i < 6; ++i)
        {
            marks[i] = a[i];
            t += a[i];
        }
        total = t;
    }
    int getTotal()
    {
        return total;
    }
    void setStd(float a, float b)
    {
        avg = a;
        st = b;
    }
    void setGrade()
    {
        if (total >= avg + 1.5 * st)
            grade = 'S';
        else if (total >= avg + 0.5 * st)
            grade = 'A';
        else if (total >= avg - 0.5 * st)
            grade = 'B';
        else if (total >= avg - 1 * st)
            grade = 'C';
        else if (total >= avg - 1.5 * st)
            grade = 'D';
        else
            grade = 'E';
    }
    void display()
    {
        cout << reg_no << "\t" << s_name << "\t " << total << "\t\t " << total / 6 << "\t\t " << grade << "\n";
        // for(int i=0;i<6;++i)
        // {
        // cout<<m[i]<<" ";
        // }
        // cout<<"\n";
    }
};
int main()
{
    int n;
    Student arr[10];
    float mean = 0, st = 0;
    cout << "Enter number of students you want to enter: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string t1, t2;
        int a[6];
        cout << "Enter registration number\n";
        cin >> t1;
        cout << "Enter name of student \n";
        cin >> t2;
        cout << "Enter marks of 6 subjects \n";
        for (int i = 0; i < 6; ++i)
            cin >> a[i];

        arr[i].setReg(t1);
        arr[i].setName(t2);
        arr[i].setMarks(a);

        mean += arr[i].getTotal();
    }
    mean /= n;

    for (int i = 0; i < n; ++i)
    {
        st = (arr[i].getTotal() - mean) * (arr[i].getTotal() - mean);
    }
    st /= n;
    st = sqrt(st);
    cout << "Reg. number \t"<< "Name \t"<< "Total Marks \t "<< "Average \t " << " Grade \n ";
        for (int i = 0; i < n; ++i)
    {
        arr[i].setStd(mean, st);
        arr[i].setGrade();
        arr[i].display();
    }
    cout << " Class Mean -->" << mean << "\n";
    cout << "Class Standard Deviation ->>" << st << "\n";
}