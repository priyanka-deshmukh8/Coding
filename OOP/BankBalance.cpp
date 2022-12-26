#include <iostream>
#include <stdlib.h>

using namespace std;

class SavingsAccount
{
private:
    double balance;
    static int intrest;

public:
    SavingsAccount() : balance(0.0)
    {
    }
    void set_balance(double x)
    {
        balance = (x >= 0) ? x : 0;
    }
    void set_intrest(int x)
    {
        intrest = (x >= 0) ? x : 0;
    }
    SavingsAccount(double x)
    {
        set_balance(x);
    }
    double get_balance(void)
    {
        return balance;
    }
    int get_intrest(void)
    {
        return intrest;
    }
    void show()
    {
        cout << " \n\nYOUR BALANCE ==" << get_balance() << "    WITH " << get_intrest() << "  %INTREST RATE ";
    }
    void read()
    {
        double total, x, p;

        cout << " ENTER DEPOSIT AMOUNT        ";
        cin >> x;
        total = get_balance() + x;
        p = calculatemothlyIntrest(total);
        p = total + p;

        set_balance(p);
    }

    double calculatemothlyIntrest(double x)
    {
        double y;
        y = ((x * get_intrest()) / 100);
        y = y / 12;
        return y;
    }
    void set_intrestrate()
    {

        int x;
        cout << "ENTER ENTREST RATE  ";
        cin >> x;
        set_intrest(x);
        //	x=get_balance()+x;

        set_balance(get_balance() + calculatemothlyIntrest(get_balance()));
    }
    ~SavingsAccount()
    {
        cout << "__________";
    }
};
int SavingsAccount::intrest = 3;
int main()
{
    SavingsAccount saver1(2000.0), saver2(3000.0);
    cout << "\n\nENTER 1 FOR SAVER1 \n\n ENTER 2 FOR SAVER 2==========";
    int x, y;
    cin >> x;
    if (x == 1)
    {
        for (int i = 0; i < 8; i++)
        {
            cout << "\n\nENATE 1 ( SHOW BALANCE)";
            cout << "\n\nENTET 2 (DEPOSIT AMOUNT)";

            cout << "\n\nENTER 3 (SET INTREST RATE)";
            cout << "\n\nENTER 4(MONTHALY INTREST )";
            cout << "\n\nENTER 5 (DISPLAY INTREST RATE)";
            cout << "__";
            cin >> y;

            if (y == 1)
                saver1.show();
            if (y == 2)
                saver1.read();
            if (y == 3)
                saver1.set_intrestrate();
            if (y == 4)
                cout << "\n\nANNUAL INTRRST RATE  " << saver1.calculatemothlyIntrest(saver1.get_balance());

            if (y == 5)
                cout << saver1.get_intrest();
        }
    }
    if (x == 2)
    {
        for (int i = 0; i < 8; i++)
        {
            cout << "\n\nENATE 1 (SHOW BALANCE)";
            cout << "\n\nENTET 2  (DEPOSIT AMOUNT)";

            cout << "\n\nENTER 3 (SET INTREST RATE)";
            cout << "\n\nENTER 4 (MONTHALY INTREST )";
            cout << "\n\nENTER 5 (DISPLAY INTREST RATE)";
            cout << "_____";
            cin >> y;
            if (y == 1)
                saver2.show();
            if (y == 2)
                saver2.read();
            if (y == 3)
                saver2.set_intrestrate();
            if (y == 4)
                cout << "\n\nANNUAL INTRRST RATE  " << saver2.calculatemothlyIntrest(saver2.get_balance());
            if (y == 5)
                cout << saver2.get_intrest();
        }
    }
}