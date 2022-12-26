#include <iostream>
#include <cmath>

using namespace std;

void fun1();
void fun2();

const float PI=3.14F;

//interface
class Shape
{
public:
    virtual void show()=0;
    virtual float area()=0;
    virtual float volume()=0;
    virtual void read()=0;
    virtual char* name()=0;
};

class Point : public Shape
{
private:
    float x, y;
public:
    Point():Point(0,0) {}
    Point(float x, float y){set(x, y);}

    void setX(float x){this->x=x;}
    float getX(){return x;}

    void setY(float y){this->y=y;}
    float getY(){return y;}

    void set(float x, float y)
    {setX(x); setY(y);}

    void show()
    {
        cout<<"I am a "<<name()<<endl;
        cout<<"x = "<<getX()<<endl<<"y = "<<getY()<<endl;
    }

    char* name(){return "Point";}
    float area(){return 0;}
    float volume(){return 0;}
    void read()
    {
        float x, y;
        cout<<"Enter value of x: "; cin>>x;
        cout<<"Enter value of y: "; cin>>y;
        set(x, y);
    }
};

class Circle : public Point
{
private:
    float r;

public:
    Circle(){setR(1);}
    Circle(float x, float y, float r):Point(x, y)
    {setR(r);}

    void setR(float r){this->r = (r>0)?r:1;}
    float getR(){return r;}

    void set(float x, float y, float r)
    {
        Point::set(x, y);  //set() of Point called
        setR(r);
    }

    void show()
    {
        Point::show();
        cout<<"r = "<<getR()<<endl;
    }

    char* name(){return "Circle";}
    float area(){return PI*getR()*getR();}
    float volume(){return 0;}
    void read()
    {
        Point::read();
        cout<<"Enter value of r: "; float r; cin>>r;
        setR(r);
    }
};

class Cone : public Circle
{
private:
    float h;

public:
    Cone(){setH(1);}
    Cone(float x, float y, float r, float h):Circle(x, y, r)
    {setH(h);}

    void setH(float h){this->h = (h>0)?h:1;}
    float getH(){return h;}

    void set(float x, float y, float r, float h)
    {
        Circle::set(x, y, r);  //set() of Circle called
        setH(h);
    }

    void show()
    {
        Circle::show();
        cout<<"h = "<<getH()<<endl;
    }
    float area()
    {
        float r = getR();
        float h = getH();
        float area = PI*r*r + PI*r*(sqrt(r*r+h*h));
        return area;
    }
    float volume()
    {
        float r = getR();
        float h = getH();
        float vol = (PI*r*r*h)/3;
        return vol;
    }
    void read()
    {
        Circle::read();
        cout<<"Enter value of h: "; float h; cin>>h;
        setH(h);
    }
    char* name(){return "Cone";}
};

int main()
{
    fun1();
    //fun2();

    return 0;
}

void fun1()
{
    cout<<"How many objects you want to create: ";int n;cin>>n;
    Shape** a;
    a = new Shape *[n]; //an array of size n, of Shape pointers
    //Shape* a[n];

    for (int i=0; i<n; ++i)
    {
        int ch;
        cout<<endl<<endl<<"Which type of object, 1- Point, 2-Circle 3-Cone"<<endl;
        cout<<"Enter your choice: "; cin>>ch;

        switch (ch)
        {
            case 1: a[i] = new Point(); break;
            case 2: a[i] = new Circle(); break;
            case 3: a[i] = new Cone(); break;
            default: cout<<"Invalid choice, Choose again"<<endl; --i; continue;
        }
        cout<<endl<<"Enter data for a "<<a[i]->name()<<endl;
        a[i]->read();
    }

    for (int i=0; i<n; ++i)
    {
        cout<<endl<<endl;
        a[i]->show();
        cout<<"My area is: "<<a[i]->area()<<endl;
        cout<<"My volume is: "<<a[i]->volume()<<endl;
    }

    //deallocate space of individual objects
    for (int i=0; i<n; ++i)
        delete a[i];

    //free the array of Shape pointers
    delete[] a;
}

class Sample
{


};

void fun2()
{
    cout<<sizeof(Shape)<<endl;
    cout<<sizeof(Point)<<endl;
    cout<<sizeof(Circle)<<endl;
    cout<<sizeof(Cone)<<endl;

    cout<<sizeof(Sample)<<endl;
}