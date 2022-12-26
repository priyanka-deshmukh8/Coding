#include <iostream>
using std::cout;
using std::endl;
int cube(int y); // function prototype
int main()
{
    int x;
    // loop 10 times, calculate cube of x and output results
    for (x = 1; x <= 10; x++)
        cout << cube(x) << endl;
    return 0; // indicates successful termination
} // end main
// definition of function cube
int cube(int y)
{
    return y * y * y;
}