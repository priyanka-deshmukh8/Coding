#include <iostream>
using namespace std;
void result(int k);
bool check(char a[][5]);
void player(char a[][5]);
void play(char a[][5], int p);
void structure(char a[][5]);
//char  a[5][5];

void play(char a[][5], int p)
{
    char k;

    if (p == 0)

        k = 'o';

    if (p == 1)

        k = '#';
    int v;

    cout << "enter place (1-9)";
    cin >> v;

    if (v == 1)

        a[0][0] = k;

    if (v == 2)

        a[0][2] = k;

    if (v == 3)

        a[0][4] = k;

    if (v == 4)

        a[2][0] = k;

    if (v == 5)

        a[2][2] = k;

    if (v == 6)

        a[2][4] = k;

    if (v == 7)

        a[4][0] = k;

    if (v == 8)

        a[4][2] = k;

    if (v == 9)

        a[4][4] = k;
    //	structure(a);
    cout << k << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << ("%c", a[i][j]);
        }
        cout << '\n';
    }
}

void structure(char a[][5])
{

    a[0][0] = '    ';
    a[0][1] = '||';
    a[0][2] = '   ';
    a[0][3] = '||';
    a[0][4] = '   ';
    a[1][0] = '==';

    a[1][1] = '+';
    a[1][2] = '==';

    a[1][3] = '+';

    a[1][4] = '==';
    a[2][0] = '   ';

    a[2][1] = '||';
    a[2][2] = '   ';
    a[2][3] = '||';
    a[2][4] = '   ';
    a[3][0] = '==';
    a[3][1] = '+';
    a[3][2] = '==';
    a[3][3] = '+';
    a[3][4] = '==';
    a[4][0] = '   ';
    a[4][1] = '||';
    a[4][2] = '   ';
    a[4][3] = '||';
    a[4][4] = '   ';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << ("%c", a[i][j]);
        }
        cout << '\n';
    }
}
void player(char a[][5])

{
    int k, p = 0;
    //	structure(a);

    for (int i = 0; i < 9; i++)
    {

        cout << "player 1";
        k = 0;
        play(a, k);
        if (check(a) == 1)
        {
            result(k);
            cout << " \n\nthank you";

            break;
        }

        cout << "player 2";
        k = 1;
        play(a, k);
        if (check(a) == 1)
        {
            result(k);
            cout << "\n\n thank you";

            break;
        }
        p++;

        if (p > 4)
        {
            cout << " draw match";
            cout << "thank you";
            exit(1);
        }
    }
}

bool check(char a[][5])
{

    if ((a[0][0] == 'o') && (a[0][2] == 'o') && (a[0][4] == 'o'))
        return 1;
    if ((a[2][0] == 'o') && (a[2][2] == 'o') && (a[2][4] == 'o'))
        return 1;
    if ((a[4][0] == 'o') && (a[4][2] == 'o') && (a[4][4] == 'o'))
        return 1;
    if ((a[0][0] == 'o') && (a[2][0] == 'o') && (a[4][0] == 'o'))
        return 1;
    if ((a[0][2] == 'o') && (a[2][2] == 'o') && (a[4][2] == 'o'))
        return 1;
    if ((a[0][4] == 'o') && (a[2][4] == 'o') && (a[5][4] == 'o'))
        return 1;
    if ((a[0][0] == 'o') && (a[2][2] == 'o') && (a[4][4] == 'o'))
        return 1;
    if ((a[4][0] == 'o') && (a[2][2] == 'o') && (a[0][4] == 'o'))
        return 1;

    if ((a[0][0] == '#') && (a[0][2] == '#') && (a[0][4] == '#'))
        return 1;
    if ((a[2][0] == '#') && (a[2][2] == '#') && (a[2][4] == '#'))
        return 1;
    if ((a[4][0] == '#') && (a[4][2] == '#') && (a[4][4] == '#'))
        return 1;
    if ((a[0][0] == '#') && (a[2][0] == '#') && (a[4][0] == '#'))
        return 1;
    if ((a[0][2] == '#') && (a[2][2] == '#') && (a[4][2] == '#'))
        return 1;
    if ((a[0][4] == '#') && (a[2][4] == '#') && (a[5][4] == '#'))
        return 1;
    if ((a[0][0] == '#') && (a[2][2] == '#') && (a[4][4] == '#'))
        return 1;
    if ((a[4][0] == '#') && (a[2][2] == '#') && (a[0][4] == '#'))
        return 1;

    return 0;
}

void result(int k)
{

    //checking winner
    if (k == 0)

        cout << "The winner is player 1";

    if (k == 1)

        cout << ("The winner is player 2");
}

int main()
{
    char a[5][5];
    cout << "SHRADDHA AGRAWAL\n";
    structure(a);
    player(a);
}