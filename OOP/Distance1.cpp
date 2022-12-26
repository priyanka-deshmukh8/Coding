#include <iostream> //distance2.cpp
using namespace std;
class Distance
{ //English Distance class
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) //constructor (no args)
    {
    }
    Distance(int ft, float in) : feet(ft), inches(in) //constructor (two args)
    {
    }
    void getdist()
    { //get length from user
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdist() const //display distance; const member function
    {
        cout << feet << "\'-" << inches << '\"';
    }
    void add_dist(Distance, Distance); //prototype declaration
    void sub_dist(Distance, Distance); //prototype declaration
};                                     //end of class
// member function to add two distances
void Distance::add_dist(Distance d2, Distance d3)
{
    feet = d2.feet + d3.feet;       //add feet
    inches = d2.inches + d3.inches; //add the inches
    if (inches >= 12.0)
    {                    //if total exceeds 12.0, it is a carry then decrease inches
        inches -= 12.0; //by 12.0 and
        feet++;          //increase feet by 1, add carry
    }
} // end of function
// member function to subtract two distances
void Distance::sub_dist(Distance d2, Distance d3)
{
    feet = d2.feet - d3.feet;       //subtract feet
    inches = d2.inches - d3.inches; //subtract the inches
    if (inches < 0.0)
    {                    //if net is less than 0, it is a carry then increase inches
        inches += 12.0; //by 12.0 and
        feet --;        //decrease feet by 1, subtract carry
    }
} // end of function
int main( ) 
{
 Distance d1, d3; //define two lengths
 Distance d2(11, 6.25); //define and initialize d2
 d3.getdist( ); //get d3 from user
 
 d1.add_dist(d2, d3); //d1 = d2 + d3;
 cout << endl << "d1 = ";
 d1.showdist(); //display resultant length
 
 d1.sub_dist(d2, d3); //d1 = d2 - d3
 cout << endl <<" d1 ="; 
 d1.showdist();
 cout << endl;
 return 0;
}