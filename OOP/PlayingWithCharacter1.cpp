#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   char ch;
scanf("%c",&ch);
char s[20];
scanf("%s",s);
char t;
scanf("%c",&t);
char sen[100];
scanf("%[^\n]",sen);
printf("%c\n",ch);
printf("%s\n",s);
printf("%s\n",sen);
    return 0;
}
