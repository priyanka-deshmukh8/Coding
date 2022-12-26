#include <iostream>

using namespace std;

void readDistinct(int a[], int n);
void show(int a[], int n);

int main()
{
    int n;

    cout<< "Enter size of array: "; 
    cin>>n;
    
    int a[n];

    readDistinct(a, n);
    show(a , n);

    return 0;
}

void readDistinct(int a[], int n)
{
    for (int i=0; i<n; ++i)
    {
        cout << "Enter next element a[" << i <<"]: ";
        cin>>a[i];
        for (int j=i-1; j>=0; --j)
        {
            while (a[i] == a[j])
            {
                cout << a[i] << " is a duplicate number enter again"<<endl;
                --i;
                break;
            }
        }
    }
}

void show(int a[], int n)
{
    cout << "Array is: ";

    for (int i=0; i<n; ++i)
        cout << a[i] << " ";

    cout<<endl;
}