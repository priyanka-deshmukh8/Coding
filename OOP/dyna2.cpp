#include<iostream>
using namespace std;

int main()
{
   int *p,n,i;
   cout<<"Enter the size:";
   cin>>n;
   p=new int[n];
   if(p==NULL)
   {
       cout<<"\n Memory not allocated";
       exit(1);
   }
   for(i=0;i<n;i++)
   {
       cout<<"Enter the element:";
       cin>>*(p+i);
   }
   for(i=0;i<n;i++)
   {
       cout<<*(p+i)<<endl;
      
   }
    delete[] p;
    return 0;
}