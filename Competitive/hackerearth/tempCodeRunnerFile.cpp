#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int first, second, sum, diff;
    cin>>first>>second;
     (first > second) ?   ((diff = first - second), printf("%d", diff)):((sum = first + second), printf("%d", sum));
}
