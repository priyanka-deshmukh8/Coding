#include <iostream>

using namespace std;

class Time24
{
private:
    int hh, mm, ss;

public:
    Time24()
    {set(0,0,0);}
    Time24(int h, int m, int s)
    {set(h, m, s);}

    void setHour(int h)
    {hh = (0<=h && h<24) ? h : 0;}
    int getHour() const
    {return hh;}
    void setMin(int m)
    {mm = (0<=m && m<60) ? m : 0;}
    int getMin() const
    {return mm;}
    void setSec(int s)
    {ss = (0<=s && s<60) ? s : 0;}
    int getSec() const
    {return ss;}

    void set(int h, int m, int s)
    {
        setHour(h);
        setMin(m);
        setSec(s);
    }
    void show()  const
    {cout<<"Time is: "<<getHour()<<":"<<getMin()<<":"<<getSec()<<endl;}

    //display time in 12 hour format : assignment
    void show12() const
    {

    }

    void read()
    {
        int h, m, s;
        cout<<"Enter hour: ";   cin >> h;
        cout<<"Enter minute: "; cin >> m;
        cout<<"Enter second: "; cin >> s;
        set(h, m, s);
    }
};

int main()
{
    Time24 t1(100, -20, 300);
    //Time24 t1 = Time24(100, -20, 300);

    t1.show();

    t1.set(50, 20, 40);
    t1.show();
    t1.setHour(18);
    t1.show();

    t1.read();
    t1.show();

    return 0;
}