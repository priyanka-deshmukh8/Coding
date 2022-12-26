#include<iostream>
class Counter
{
private:
     int count;
public:
      Counter(int c=0):count(c)
      {}
      //setter function
      void set_count(int c)
      {
          count =c;
      }
      //function to get value
      int get_count()
      {
          return count;
      }
      //function to increment
      void increment()
      {
          count++;
        
      }
      void decrement()
      {
          count--;
      }
};//end of class
int main()
{
    Counter c1;//default ctor
    Counter c2(100);//parameterized ctor called
   // c2.count=100;

    std::cout <<"\n"<< c1.get_count()<<"\n"<<c2.get_count() << std::endl;
     c1.increment();
     c1.increment();
     c2.decrement();
     std::cout << "\n"<<c1.get_count()<<"\n"<<c2.get_count() << std::endl;
    return 0;

}