#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char str[100];
    int i = 0, j = 0, k = 0, n = 0, o = 0;
    puts("Enter any Sentance");
    gets(str);
    n = strlen(str);
    while (str[i] != '\0')
    {
        if ((str[i] >= 65) && (str[i] < 97))
        {
            j++;
        }
        if ((str[i] >= 97) && (str[i] < 122))
        {
            k++;
        }
        if (str[i] == ' ')
        {
            o++;
        }
        i++;
    }
    cout << "The Total number of characters= " << n;
    cout << "\nThe Total number of white spaces= " << o;
    cout << "\nThe Total number of upper case letters= " << k;
    cout << "\nThe Total number of lower case letters= " << j;
    return 0;
}                                                                                                                                                                                     