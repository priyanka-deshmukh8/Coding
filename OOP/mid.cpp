#include<stdio.h>
#include<conio.h>
int main()
{
    int i, j, size, dash;
    char ch='A';
    printf("Enter size: ");
    scanf("%d", &size);
    dash = size-1;
    for(i=1; i<=size; i++)
    {
        for(j=1; j<=(dash); j++)
            printf(" ");
        dash--;
        for(j=1; j<=(2*i-1); j++)
        {
            printf("%c", ch);
            ch++;
        }
        ch='a'+dash;
        printf("\n");
    }
    dash = 1;
    for(i=1; i<=(size-1); i++)
    {
        for(j=1; j<=(dash); j++)
            printf(" ");
        dash++;
        for(j=1; j<=(2*(size-i)-1); j++)
        {
            printf("%c", ch);
            ch++;
        }
        ch='A';
        printf("\n");
    }
    getch();
    return 0;
}