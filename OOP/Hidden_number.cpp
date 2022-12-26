//Program by Priyanka
//Program to find out the number which computer has supposed randomly
//#############   LET'S PLAY A GAME    ##############
#include<iostream>
#include <stdlib.h>
#include<ctime>

using namespace std;
 
int main(void)
{
    int n,k,c=0;
    srand(time(0));
    k =rand()%100;
    cout<<"Computer has selected a number b/w 0-100 and saved it in memory "<<endl;

do
{    
    cout<<"\n Enter a number to find out the hidden number=";
    cin>>n;
    c++;
    if(n>k)
         cout<<"Your number is greater "<<endl;
    if(n<k)
          cout<<"Your number is smaller"<<endl;
    if(n==k)
    {
        cout<<endl;
        cout<<"The number is"<<k<<endl;
        cout<<"You Successfully found the number after "<<c<<" mistakes";
        exit(0); //stop the working
    }
}
while(n!=k);
} 