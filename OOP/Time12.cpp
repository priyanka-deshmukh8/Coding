#include <iostream>

using namespace std;

class Time24
{
private:
    int hh = 0, mm = 0, ss = 0;

public:
    //member initializer list
    //it can only be used in ctor to initialize member data
    Time24() : hh(0), mm(0), ss(0)
    {
    }

    Time24(int h, int m, int s)
    {
        set(h, m, s);
    }

    void setHour(int h)
    {
        hh = (0 <= h && h < 24) ? h : 0;
    }
    int getHour() const
    {
        return hh;
    }
    void setMin(int m)
    {
        mm = (0 <= m && m < 60) ? m : 0;
    }
    int getMin() const
    {
        return mm;
    }
    void setSec(int s)
    {
        ss = (0 <= s && s < 60) ? s : 0;
    }
    int getSec() const
    {
        return ss;
    }

    void set(int h, int m, int s)
    {
        setHour(h);
        setMin(m);
        setSec(s);
    }
    void show() const
    {
        cout << "Time is: " << getHour() << ":" << getMin() << ":" << getSec() << endl;
    }

    //display time in 12 hour format : assignment
    void show12() const
    {
    }

    void read()
    {
        int h, m, s;
        cout << "Enter hour: ";
        cin >> h;
        cout << "Enter minute: ";
        cin >> m;
        cout << "Enter second: ";
        cin >> s;
        set(h, m, s);
    }

    //to add one second in the current Time object
    void tick()
    {
        setSec(getSec() + 1); //ss = ss+1;
        if (getSec() == 0)
        {
            setMin(getMin() + 1); //mm = mm + 1;
            {
                if (getMin() == 0)
                    setHour(getHour() + 1); //hh = hh +1
            }
        }
    }

    void addNSeconds(int n)
    {
        for (int i = 0; i < n; ++i)
            tick();
    }
};

int main()
{
    Time24 t1;
    t1.show();

    t1.set(23, 59, 59);
    t1.show();

    t1.tick();
    t1.show();

    t1.addNSeconds(10000);
    t1.show();

    return 0;
}