#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 30;
void fun1();

class Exception
{
private:
    string m;

public:
    Exception(string m) { setMessage(m); }
    void setMessage(string m) { this->m = m; }
    string getMessage() { return m; }
};

class Overflow : public Exception
{
private:
    float x;

public:
    Overflow(float x, char *m) : Exception(m)
    {
        setX(x);
    }
    void setX(float x) { this->x = x; }
    float getX() { return x; }
    void set(float x, char *m)
    {
        setX(x);
        setMessage(m);
    }
};

class Underflow : public Exception
{
public:
    Underflow(char *m) : Exception(m) {}
};

class Stack
{
private:
    float *a;
    int top;
    int size;

public:
    Stack() : Stack(5) {}
    Stack(int n)
    {
        size = (n > 0) ? n : 5;
        a = new float[size];
        initialize();
    }

    void initialize()
    {
        top = -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }

    void push(float x)
    {
        if (isFull())
        {
            Overflow o(x, "Stack Overflow");
            throw o;
        }
        //otherwise push item onto the stack
        a[++top] = x;
    }

    float pop()
    {
        if (isEmpty())
        {
            Underflow u("Stack underflow");
            throw u;
        }
        //otherwise pop top most item from the stack
        float x;
        x = a[top--];
        return x;
    }

    float peep() //to get the top most item without removing it
    {
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
            return a[top];
    }

    void show()
    {
        cout << "Stack is: ";
        for (int i = 0; i <= top; ++i)
            cout << a[i] << "\t";
        cout << endl;
    }

    ~Stack() { delete[] a; }
};

int main()
{
    fun1();
    cout << "Exiting from program" << endl;
    return 0;
}

void fun1()
{
    Stack s;
    float x;

    //try contains those statements that may generate exception
    try
    {
        x = 20;
        s.push(x);
        x = 10;
        s.push(x);
        x = 30;
        s.push(x);
        x = 100;
        s.push(x);
        s.show();

        x = 70;
        s.push(x);
        s.show();

        Exception e("Base class exception  occured");
        throw e;

        x = 700;
        s.push(x); //overflow

        while (!s.isEmpty())
        {
            x = s.pop();
            cout << x << endl;
        }

        //x = s.pop();    //underflow
    }
    catch (Overflow o)
    {
        cout << o.getMessage() << " due to pushing of " << o.getX() << endl;
    }
    catch (Underflow u)
    {
        cout << u.getMessage() << endl;
    }
    catch (Exception e)
    {
        cout << "Exception occurred" << endl;
    }
    catch (...) //catch all exception handler
    {
        cout << "Unknown exception occurred" << endl;
    }
}