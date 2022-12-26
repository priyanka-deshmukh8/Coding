#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool flip(void);
int main()
{
    int n, x, tcount  = 0, hcount = 0;
    cout << "Enter count : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if(flip()==1)
        {
            cout << "Heads" << endl;
            hcount++;
        }
        else
        {
            cout << "Tails" << endl;
            tcount++;
        }
    }
    cout << "Heads : " << hcount << endl << "Tails : " << tcount << endl;
    
}
bool flip(void)
{
    return rand()%2;

}