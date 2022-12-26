#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX = 40;

class Student
{
private:
    int roll;
    char name[MAX];
    int age;
    int techni_english, maths1_marks, maths2_marks, compu_marks, cpp_marks;
    double average;
    char grade;

public:
    void setRoll(int r) { roll = (0 < r && r < 1000) ? r : 1; }
    int getRoll() { return roll; }

    void setName(char n[]) { strcpy(name, n); }
    char *getName() { return name; }

    void setAge(int a) { age = (0 < a && a < 100) ? a : MAX; }
    int getAge() { return age; }

    void set(int r, char n[], int a)
    {
        setRoll(r);
        setName(n);
        setAge(a);
    }
    int calculate()
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
    void show()
    {
        cout << "\nEnrollment number of Student : " << getRoll();
        cout << "\nName of Student : " << getName();
        cout << "\n Age of Student : " << getAge();
        cout << "\nTechnical English : " << techni_english;
        cout << "\nLinear Algebra : " << maths1_marks;
        cout << "\nDifferential Equation : " << maths2_marks;
        cout << "\nComputer Architecture And logic Design : " << compu_marks;
        cout << "\nObject Oriented Programming with C++:" << cpp_marks;
        cout << "\nPercentage :" << average;
        cout << "\nGrade of Student is :" << grade;
    }
    int retrollno() const
    {
        return roll;
    }
    void read()
    {
        char n[MAX];
        int r, a;
        cout << "\n\nEnter roll: ";
        cin >> r;
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 40);
        cout << "Enter age: ";
        cin >> a;
        set(r, n, a);
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
};

class Class
{
private:
    char name[20];
    int size;
    Student *s;

public:
    Class(char n[], int sz)
    {
        setName(n);
        setSize(sz);
        s = new Student[size];
    }
    void setName(char n[]) { strcpy(name, n); }
    char *getName() { return name; }

    void setSize(int sz) { size = (0 < sz && sz < 120) ? sz : 60; }
    int getSize() { return size; }

    void writeClassOnFile()
    {
        fstream fs;
        char fileName[25];
        strcpy(fileName, name);
        strcat(fileName, ".dat");

        fs.open(fileName, ios::out);
        if (fs.good() != 1)
        {
            cout << "File not open" << endl;
            exit(1);
        }
        fs.write((char *)s, sizeof(Student) * size);
    }
    void readClassFromFile()
    {
        fstream fs;
        char fileName[25];
        strcpy(fileName, name);
        strcat(fileName, ".dat");

        fs.open(fileName, ios::in);
        if (fs.good() != 1)
        {
            cout << "File not open" << endl;
            exit(1);
        }
        fs.read((char *)s, sizeof(Student) * size);
    }

    void readClassKB()
    {
        for (int i = 0; i < getSize(); ++i)
            s[i].read();
        writeClassOnFile();
    }

    void showFullClass()
    {
        Student st;
        ifstream inFile;
        inFile.open("Student.dat", ios::binary);
        if (!inFile)
    {
        cout << "File could not be opened !! Press any Key to exit";
        
        cin.get();
        return;
    }
        cout << "\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
        while (inFile.read(reinterpret_cast<char *>(&st), sizeof(Student)))
        {
            st.show();
            cout << "\n\n====================================\n";
        }
        inFile.close();
        
        cin.get();
    }
    void ModifyStudentData(int roll)
    {
        fstream fs;
        char fileName[25];
        strcpy(fileName, name);
        strcat(fileName, ".dat");

        fs.open(fileName, ios::app);
        if (fs.good() != 1)
        {
            cout << "File could  not be open.." << endl;
            exit(1);
        }

        Student st;
        st.show();
        cout << "\nEnter new Student details:" << endl;
        st.read();
        int pos = (-1) * static_cast<int>(sizeof(st));
        fs.seekp(pos, ios::cur);
        fs.write(reinterpret_cast<char *>(&st), sizeof(Student));
        cout << "\n\n\t Record Updated";
    }

    //to search student with roll number roll
    int search(int roll)
    {
        readClassFromFile();
        for (int i = 0; i < getSize(); ++i)
            if (roll == s[i].getRoll())
                return i; //fount at index i
        return -1;        //not found
    }
    void showOneStudent(int roll)
    {
        int i = search(roll);
        if (i == -1)
            cout << "Student not found" << endl;
        else
            s[i].show();
    }
    void delete_Student(int roll)
    {
        Student st;
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
        while (iFile.read(reinterpret_cast<char *>(&st), sizeof(Student)))
        {
            if (st.retrollno() != roll)
            {
                oFile.write(reinterpret_cast<char *>(&st), sizeof(Student));
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

    ~Class() { delete[] s; }
};

int main()
{
    int n;
    cout << "Enter size of class: ";
    cin >> n;
    Class c("M", n);
    char ch;
    do
    {
        int roll;
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
            c.readClassKB();
            break;
        case '2':
            cout << "\n\n\tEnter The roll number ";
            cin >> roll;
            c.showOneStudent(roll);
            break;
        case '3':
            c.showFullClass();
            break;
        case '4':
            cout << "\n\n\tEnter The roll number: ";
            cin >> roll;
            c.delete_Student(roll);
            break;
        case '5':
            cout << "\n\n\tEnter The roll number ";
            cin >> roll;
            c.ModifyStudentData(roll);
            (roll);
            break;
        case '6':
            cout << "Exiting, Thank you!";
            exit(0);
        }
    } while (ch != '6');
    return 0;
}
