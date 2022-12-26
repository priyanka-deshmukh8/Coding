#include<iostream>

using namespace std;
 
 int  main()
 {
     const float PI=3.14;
     float r,area;
     cout<<" Enter radius of circle:";
     cin>>r;
     area=PI*r*r;
     cout<<"Area of circle is:"<<area;
     return 0;
}