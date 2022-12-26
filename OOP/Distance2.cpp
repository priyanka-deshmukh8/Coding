#include <iostream>
using namespace std;
class Distance
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0)
    {
    }
    Distance(int ft, float in) : feet(ft), inches(in)
    {
    }
    void getDistance()
    {
        std::cout << "Enter feet:" << std::endl;
        std::cin >> feet;
        std::cout << "Enter inches:" << std::endl;
        std::cin >> inches;
    }
    void showDistance()
    {
        std::cout << feet << "\'-" << inches << "'\'" << std::endl;
    }
    Distance add_dist(Distance); //add
};
Distance Distance::add_dist(Distance d2)
{
    Distance temp; //temporary variable
    temp.inches = inches + d2.inches;
    if (temp.inches >= 12.0)     //if total exceeds 12.0,
    {                            //then decrease inches
        temp.inches -= 12.0;     //by 12.0 and
        temp.feet = 1;           //increase feet
    }                            //by 1
    temp.feet += feet + d2.feet; //add the feet
    return temp;
} // end of function
int main() {
 Distance d1, d3; //define two lengths
 Distance d2(11, 6.25); //define, initialize dist2
 d1.getDistance(); //get dist1 from user
 d3 = d1.add_dist(d2); //d3 = d1 + d2
 cout << "\ndist1 = "; d1.showDistance();
 cout << "\ndist2 = "; d2.showDistance();
 cout << "\ndist3 = "; d3.showDistance();
 cout << endl;
 return 0;
 }