#include<stdio.h>

int main()
{
    int& x = 10;   //lvalue is non const and rvalue is constant
    const int& y = 10;  //no error because both lvalue and rvalue is of type const
    printf("x=%d,y=%d",x,y);

}