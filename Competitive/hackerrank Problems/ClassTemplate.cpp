#include<bits/stdc++.h>
using namespace std;

template <class T> class AddElement{
    public:
    T element;
    AddElement(T i){
        element=i;
    }
    T add(T i){return element+1;}
};
template <> class AddElement<string>
{
   public:
   string element;
   AddElement(string i){element =i;}
   string concatenate(string element2){return element+element2;}
};

int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        string type;
        cin>>type;
        if(type=="float")
        {
            double element1,element2;
            cin>>element1>>element2;
            AddElement <double>myfloat(element1);
            cout<<myfloat.add(element2)<<endl;
        }
        else if (type=="int")
        {
            int element1,element2;
            cin>>element1>>element2;
            AddElement<int>myint(element1);
            cout<<myint.add(element2)<<endl;
        }
        else if (type=="string")
        {
            string element1,element2;
            cin>>element1>>element2;
            AddElement<string> mystring(element1);
            cout<<mystring.concatenate(element2)<<endl;
        }
    }

    return 0;
}
