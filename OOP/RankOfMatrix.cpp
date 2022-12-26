#include <iostream>
using namespace std;
class Rank
{
private:
    int a[3][3];

public:
    Rank()
    {
        a[2][2] = 0;
    }
    void set_array(int x, int i, int j)
    {
        a[i][j] = x;
    }

    void read(void);
    int rank(void);
    void show(void)
    {
        cout << " rank ==" << rank();
    }
    ~Rank()
    {
        cout << "thank you";
    }
};
void Rank::read(void)

{
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; i++)
        {
            int x;

            cout << (" enter a elemen a[%d][%d]", i, j);
            cin >> x;
            set_array(x, i, j);
        }
    }
}

int Rank ::rank()
{
    if (a[0][0](a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1](a[1][0] a[2][2] - a[2][0] * a[1][2]) + a[0][2](a[1][0] * a[2][1] - a[1][1] * a[2][0]))
        return 3;
    else if ((a[0][0] * a[1][1] - a[1][0] * a[0][1]) || (a[0][1] * a[1][2] - a[1][1] * a[0][2]) || (a[1][0] * a[2][1] - a[1][1] * a[2][0]) || (a[1][0] * a[2][1] - a[1][1] * a[2][0]) || (a[1][1] * a[2][1] - a[1][2] * a[2][1]) || (a[0][0] * a[2][1] - a[0][2] * a[2][0]))
        return 2;
    return 1;
}
int main()
{
    Rank *c;
    c = new Rank;
    (*c).read();
    // 		(*c).show();
}