
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>

using namespace std;
int check(int a[][3]);
void result(int a[][3], char s[], char p[]);

void player(char s[], char p[])
{

	cout << "\n  {X} enter first player  name::";
	cin >> s;
	//cout<<s;
	cout << "\n  {0} enter second player  name::";
	cin >> p;
	//	cout<<a;
}
void structure(void)
{
	for (int i = 0; i < 9; i++)
	{
		gotoxy(10, 6 + i);
		cout << "||         ||";
		for (int j = 0; j < 22; j++)
		{
			gotoxy(5 + j, 8);
			cout << "==";

			gotoxy(5 + j, 12);
			cout << "==";
		}
	}
}
void play(char s[], char p[])
{

	int x, y, i, j;
	int a[3][3];

	a[0][0] = 0;
	a[0][1] = 1;
	a[0][2] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	a[1][2] = 5;
	a[2][0] = 6;
	a[2][1] = 7;
	a[2][2] = 8;

	for (int i = 0; i < 9; i++)
	{
		gotoxy(4, 20);
		cout << s << "         's  turn\n";
		cout << "enter coloum(0-2)only::";
		cin >> x;
		cout << "enter row(0-2)only::";
		cin >> y;

		if (check(a))
		{
			a[x][y] = 50;
			gotoxy(8 + 8 * x, 6 + 4 * y);
			cout << "X";
		}
		else
		{
			result(a, s, p);
			break;
		}

		gotoxy(4, 20);
		cout << p << "\n";
		cout << "enter coloum(0-2)only::";
		cin >> i;

		cout << "enter row(0-2)only::";
		cin >> j;

		if (check(a))
		{
			a[i][j] = 30;
			gotoxy(8 + 8 * i, 6 + 4 * j);
			cout << "0";
		}
		else
		{

			result(a, s, p);
			break;
		}
	}
}
int check(int a[][3])
{
	if ((a[0][0] == a[0][1]) && (a[0][1] == a[0][2]))
		return 0;

	if ((a[1][0] == a[1][1]) && (a[1][1] == a[1][2]))
		return 0;

	if ((a[2][0] == a[2][1]) && (a[2][1] == a[2][2]))
		return 0;

	if ((a[0][0] == a[1][0]) && (a[1][0] == a[2][0]))
		return 0;
	if ((a[0][1] == a[1][1]) && (a[1][1] == a[2][1]))
		return 0;
	if ((a[0][2] == a[1][2]) && (a[1][2] == a[2][2]))
		return 0;
	if ((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]))
		return 0;
	if ((a[2][0] == a[1][1]) && (a[1][1] == a[0][2]))
		return 0;

	return 1;
}
void result(int a[][3], char s[], char p[])
{
	if (a[0][0] + a[0][1] + a[0][2] == 150)
		cout << s << "   has won this match";
	if (a[0][0] + a[1][0] + a[2][0] == 150)
		cout << s << "   has won this match ";

	if (a[0][0] + a[1][1] + a[2][2] == 150)
		cout << s << "   has won this match";
	if (a[0][1] + a[1][1] + a[2][1] == 150)
		cout << s << "   has won this match ";
	if (a[0][2] + a[1][2] + a[2][2] == 150)
		cout << s << "   has won this match ";
	if (a[2][0] + a[1][1] + a[0][2] == 150)
		cout << s << "  has won this match";
	if (a[2][0] + a[2][1] + a[2][2] == 150)
		cout << s << "  has won this match";
	if (a[1][0] + a[1][1] + a[1][2] == 150)
		cout << s << "  has won this match";

	if (a[0][0] + a[0][1] + a[0][2] == 90)
		cout << p << "   has won this match";

	if (a[0][0] + a[1][0] + a[2][0] == 90)
		cout << p << "   has won this match";

	if (a[0][0] + a[1][1] + a[2][2] == 90)
		cout << p << "  has won this match ";
	if (a[0][1] + a[1][1] + a[2][1] == 90)
		cout << p << "  has won this match ";
	if (a[0][2] + a[1][2] + a[2][2] == 90)
		cout << p << "   has won this match";
	if (a[2][0] + a[1][1] + a[0][2] == 90)
		cout << p << "   has won thia match";

	if (a[2][0] + a[2][1] + a[2][2] == 90)
		cout << p << "  has won this match";
	if (a[1][0] + a[1][1] + a[1][2] == 90)
		cout << p << "  has won this match";
}

int main()
{
	char s[20], p[20];
	player(s, p);

	structure();
	play(s, p);
}
