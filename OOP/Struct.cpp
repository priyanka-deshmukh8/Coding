#include<iostream>

using namespace std;

struct student
{
    int age,std;
    string first_name;
    string last_name;
};
int main()
{
    student st;
    
    cin>>st.age>>st.first_name>>st.last_name>>st.std;
    cout<<st.age<<" "<<st.first_name<<" "<<st.last_name<<" "<<st.std;
    return 0;

}