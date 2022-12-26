/*  ex02_02.cpp*/

#include <iostream>
#include <stdio.h>

using namespace std;
inline int fehrenheit(int x);
inline int celsius(int x);
int main()
{
	int i, y;
	cout << "(for °f to °c enter 1 )\n (for °c to °f enter)(2)==::";
	cin >> y;
	if (y == 2)
	{
		for (i = 0; i <= 100; i++)
		{

			cout << "\n||[temprature      " << i << "°c";

			cout << "===    ::" << fehrenheit(i) << "°F]"
				 << "||";
		}
	}
	else if (y == 1)
	{
		for (i = 0; i <= 100; i++)
		{

			cout << "\n||[temprature      " << i << "°f";

			cout << "===    ::" << celsius(i) << "°C]"
				 << "||";
		}
	}
}
int fehrenheit(int x)
{
	int temp;
	temp = x * 1.8 + 32;
	return temp;
}

int celsius(int x)
{
	int temp;

	temp = (x - 32) * 5 / 9;
	return temp;
}