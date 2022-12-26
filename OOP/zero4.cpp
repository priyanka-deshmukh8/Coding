#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 50
using namespace std;

int main()
{
	int x, y, a[max];
	int i, n, sum;
	cout << "roll time::";
	cin >> n;
	srand(time(0));
	for (i = 0; i < 10; i++)
		a[i] = 0;

	for (i = 0; i < n; i++)
	{
		x = 1 + rand() % 6;
		y = 1 + rand() % 6;

		sum = x + y;
		cout << x << "+" << y << "=" << sum << "\n";

		if (sum == 2)
			a[0]++;
		else if (sum == 3)
			a[1]++;
		else if (sum == 4)
			a[2]++;
		else if (sum == 5)
			a[3]++;
		else if (sum == 6)
			a[4]++;
		else if (sum == 7)
			a[5]++;
		else if (sum == 8)
			a[6]++;
		else if (sum == 9)
			a[7]++;
		else if (sum == 10)
			a[8]++;
		else if (sum == 11)
			a[9]++;
		else if (sum == 12)
			a[10]++;
	}

	for (i = 0; i <= 10; i++)
		printf("count of sum||%d---%dtime ||\n", 2 + i, a[i]);
}