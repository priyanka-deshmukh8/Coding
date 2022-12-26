//Program which defines some words against symbols
#include<iostream>
#include<conio.h>

#define AND && //define AND
#define OR ||
#define NOT !

int main()
{
    int c,d,n;
    std::cout << "Enter the value of n" << std::endl;
    std::cin>>n;
    std::cout << "Enter the value of c" << std::endl;
    std::cin>>c;
    std::cout << "Enter the value of d" << std::endl;
    std::cin>>d;
    if((n>c AND n>d)OR (d<n AND c!=d))
    std::cout<<"This is the example of preprocessors";
    else
    std::cout << "Invalid input" << std::endl;
    getch();
    return 0;
}
