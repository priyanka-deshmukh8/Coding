/***********************************************************************************************************************
                                     THIS PROGRAM IS DESIGNED BY
                                     ____________________________
                     __________________________________________________________________
                
    * PRIYANKA DESHMUKH                        0901MC201047                            MATHEMATICS AND COMPUTING*                    

************************************************************************************************************************/




#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// the class that stores data
class Student
{
    int rollno;
    char name[50];
    int techni_english, maths1_marks, maths2_marks, compu_marks, cpp_marks;
    double average;
    char grade;

public:
    void getdata();
    void showdata() const;
    void calculate();
    int retrollno() const;
}; //class ends here

void Student::calculate()
{
    average = (techni_english + maths1_marks + maths2_marks + compu_marks + cpp_marks) / 5.0;
    if (average >= 90)
        grade = 'A';
    else if (average >= 75)
        grade = 'B';
    else if (average >= 50)
        grade = 'C';
    else
        grade = 'F';
}

void Student::getdata()
{
    cout << "\nEnter Student's Enrollment number: ";
    cin >> rollno;
    cout << "\n\nEnter Student name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nAll marks should be out of 100";
    cout << "\nEnter marks in Technical  English: ";
    cin >> techni_english;
    cout << "\nEnter marks in linear Algebra:  ";
    cin >> maths1_marks;
    cout << "\nEnter marks in Differential Equations:  ";
    cin >> maths2_marks;
    cout << "\nEnter marks in Computer Architecture And Logic Design:  ";
    cin >> compu_marks;
    cout << "\nEnter marks in Computer Programming with c++:  ";
    cin >> cpp_marks;
    calculate();
}
void Student::showdata() const
{
    cout << "\nEnrollment number of Student : "<< rollno;
    cout << "\nName of Student : " << name;
    cout << "\nTechnical English : " << techni_english;
    cout << "\nLinear Algebra : " << maths1_marks;
    cout << "\nDifferential Equation : " << maths2_marks;
    cout << "\nComputer Architecture And logic Design : " << compu_marks;
    cout << "\nComputer Programming with C++:" << cpp_marks;
    cout << "\nPercentage :" << average;
    cout << "\nGrade of Student is :" << grade;
}
int Student::retrollno() const
{
    return rollno;
}
//function declaration
void create_Student();
void display_sp(int);     //display particular record
void display_all();       // display all records
void delete_Student(int); //delete particular record
void change_Student(int); //edit particular record
//MAIN
int main()
{
    char ch;
    cout << setprecision(2);
    do
    {
        char ch;
        int num;
        system("cls");
        cout << "\n\n\n\tMENU";
        cout << "\n\n\t1.Create Student record";
        cout << "\n\n\t2. Search Student record";
        cout << "\n\n\t3. Display all Students records ";
        cout << "\n\n\t4.Delete Student record";
        cout << "\n\n\t5.Modify Student record";
        cout << "\n\n\t6.Exit";
        cout << "\n\nWhat is your Choice (1/2/3/4/5/6) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            create_Student();
            break;
        case '2':
            cout << "\n\n\tEnter The roll number ";
            cin >> num;
            display_sp(num);
            break;
        case '3':
            display_all();
            break;
        case '4':
            cout << "\n\n\tEnter The roll number: ";
            cin >> num;
            delete_Student(num);
            break;
        case '5':
            cout << "\n\n\tEnter The roll number ";
            cin >> num;
            change_Student(num);
            break;
        case '6':
            cout << "Exiting, Thank you!";
            exit(0);
        }
    } while (ch != '6');
    return 0;
}
//write Student details to file
void create_Student()
{
    Student stud;
    ofstream oFile;
    oFile.open("Student.dat", ios::binary | ios::app);
    stud.getdata();
    oFile.write(reinterpret_cast<char *>(&stud), sizeof(Student));
    oFile.close();
    cout << "\n\nStudent record Has Been Created ";
    cin.ignore();
    cin.get();
}
// read file records
void display_all()
{
    Student stud;
    ifstream inFile;
    inFile.open("Student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
    while (inFile.read(reinterpret_cast<char *>(&stud), sizeof(Student)))
    {
        stud.showdata();
        cout << "\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}
//read specific record based on roll number
void display_sp(int n)
{
    Student stud;
    ifstream iFile;
    iFile.open("Student.dat", ios::binary);
    if (!iFile)
    {
        cout << "File could not be opened... Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (iFile.read(reinterpret_cast<char *>(&stud), sizeof(Student)))
    {
        if (stud.retrollno() == n)
        {
            stud.showdata();
            flag = true;
        }
    }
    iFile.close();
    if (flag == false)
        cout << "\n\nrecord does not exist";
    cin.ignore();
    cin.get();
}
// modify record for specified roll number
void change_Student(int n)
{
    bool found = false;
    Student stud;
    fstream fl;
    fl.open("Student.dat", ios::binary | ios::in | ios::out);
    if (!fl)
    {
        cout << "File could not be opened. Press any Key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    while (!fl.eof() && found == false)
    {
        fl.read(reinterpret_cast<char *>(&stud), sizeof(Student));
        if (stud.retrollno() == n)
        {
            stud.showdata();
            cout << "\nEnter new Student details:" << endl;
            stud.getdata();
            int pos = (-1) * static_cast<int>(sizeof(stud));
            fl.seekp(pos, ios::cur);
            fl.write(reinterpret_cast<char *>(&stud), sizeof(Student));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    fl.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}
//delete record with particular roll number
void delete_Student(int n)
{
    Student stud;
    ifstream iFile;
    iFile.open("Student.dat", ios::binary);
    if (!iFile)
    {
        cout << "File could not be opened... Press any Key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream oFile;
    oFile.open("Temp.dat", ios::out);
    iFile.seekg(0, ios::beg);
    while (iFile.read(reinterpret_cast<char *>(&stud), sizeof(Student)))
    {
        if (stud.retrollno() != n)
        {
            oFile.write(reinterpret_cast<char *>(&stud), sizeof(Student));
        }
    }
    oFile.close();
    iFile.close();
    remove("Student.dat");
    rename("Temp.dat", "Student.dat");
    cout << "\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}
/*************************************THE END***********************************************************************/