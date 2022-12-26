
#include <iostream>
using namespace std;

const int MAX = 10;

bool isOrthogonal(int a[MAX][MAX], int r, int c); //to check whether matrix is orthogonal or not 
void read(int a[MAX][MAX], int r, int c);   //to getting matrix from user
void show(int a[MAX][MAX], int r, int c);   //to display matrix
void transpose(int original[MAX][MAX], int r, int c, int transpose[MAX][MAX]); //to find transpose of a matrix
void multiply(int a[MAX][MAX], int r1, int c1, int b[MAX][MAX], int r2, int c2, int result[MAX][MAX]); //to multiply two matrix
bool isIdentity(int a[MAX][MAX], int r, int c);// if matrix is an identity matrix

void read(int a[MAX][MAX], int r, int c)
{
}
void transpose(int original[MAX][MAX], int r, int c, int transpose[MAX][MAX])
{
}
void multiply(int a[MAX][MAX], int r1, int c1, int b[MAX][MAX], int r2, int c2, int result[MAX][MAX])
{
}
bool isIdentity(int a[MAX][MAX], int r, int c)
{
}

bool isOrthogonal(int a[MAX][MAX], int r, int c)
{
}

// Driver Code
int main()
{
	do
      {
            cout << "\n\n 1.Input Matrix ";
            cout << "\n 2. Show Matrix ";
            cout << "\n 3.  ";
            cout << "\n 4. Multiplication of Rational no.";
            cout << "\n 5. Division of Rational no. ";
            cout << "\n 6. Quit";
            cout << "\n\n Enter your choice :: ";
            cin >> n;
            switch (n)
            {
            case 1:
                  cout << endl
                       << "\n enter the data for first Rational no.:: ";
                  c1.getdata();
                  cout << endl
                       << "\n enter the data for second Rational no. :: ";
                  c2.getdata();
                  break;

            case 2:
                  c= Add(c1,c2);
                  break;

            case 3:
                  c= Subtract(c1, c2);
                  break;

            case 4:
                  c1.Mult(c1,c2);
                  break;

            case 5:
                  Divide(c1,c2);
                  break;

            case 6:
                  exit(1);
                  break;
            }
      } while (n != 6);
	
	return 0;
}
