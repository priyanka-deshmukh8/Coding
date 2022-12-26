#include <iostream>

using namespace std;

class Rational
{
private:
   int numer, denom;

public:
   //whenever the value of numerator and denomenator is changed
   Rational() : numer(0), denom(1)
   {
   }
   Rational(int n, int d)
   {
      set(n, d);
   }
   void setNumerator(int n)
   {
      numer = n;
   }
   int getDenomenator() const
   {
      return denom;
   }
   int getNumerator() const
   {
      return numer;
   }
   void setDenomenator(int d)
   {
      if (d == 0)
      {
         cout << "Denomenator is 0" << endl;
         exit(1);
      }
      denom = (d != 0) ? d : 1;
   } //condition counld be replaced by d!=0
   void negativeCheck()
   {
      if ((getDenomenator() < 0 && getNumerator() < 0) || getDenomenator() < 0 && getNumerator() > 0)
      {
         setNumerator(-1 * getNumerator());
         setDenomenator(-1 * getDenomenator());
      }
   }
   void set(int n, int d)
   {
      setNumerator(n);
      setDenomenator(d);
      negativeCheck();
   }
   void reduceRational()
   {
      int cf=gcd(getNumerator(),getDenomenator());
      setNumerator(getNumerator()/cf);
      setDenomenator(getDenomenator()/cf);
      negativeCheck();
   }
   void printfloat() const
   {
      float res=(float)(getNumerator())/getDenomenator();
      cout<<res<<endl;
   }
   void printRational()
   {
      reduceRational();
      if(getNumerator()==0)
      cout<<getNumerator()<<endl;
      else if (getNumerator()==getDenomenator())
      cout<<1<<endl;
      else if (getDenomenator()==1)
      cout<<getNumerator()<<endl;
      else
      cout<<getNumerator()<<"/"<<getDenomenator()<<endl;
   }
   
   Rational operator+(Rational num2) const
   {
      Rational res_rnl;
      int new_num,new_denom;
      new_num=getNumerator()*num2.getDenomenator()+getDenomenator()*num2.getNumerator();
      new_denom=getDenomenator()*num2.getDenomenator();
      res_rnl=Rational(new_num,new_denom);
      res_rnl.reduceRational();
      return res_rnl;
   }
   Rational operator-(Rational num2) const
   {
      Rational res_rnl;
      int new_num,new_denom;
      new_num=getNumerator()*num2.getDenomenator()-getDenomenator()*num2.getNumerator();
      new_denom=getDenomenator()*num2.getDenomenator();
      res_rnl=Rational(new_num,new_denom);
      res_rnl.reduceRational();
      return res_rnl;
   }
   Rational operator*(Rational num2) const
   {
      Rational res_rnl;
      int new_num,new_denom;
      new_num=getNumerator()*num2.getDenomenator();
      new_denom=getDenomenator()*num2.getDenomenator();
      res_rnl=Rational(new_num,new_denom);
      res_rnl.reduceRational();
      return res_rnl;
   }
   Rational operator/(Rational num2) const
   {
      int new_num,new_denom;
      Rational res_rnl;
      new_num=getNumerator()*num2.getDenomenator();
      new_denom=getDenomenator()*num2.getNumerator();
      res_rnl=Rational(new_num,new_denom);
      res_rnl.reduceRational();
      return res_rnl;
   }
   ~Rational()
   {}

int gcd(int a,int b)
{
   //could also be done without using recursion using Euclid's Algorithm.
   if(b==0)
      return a;
      return gcd(b,a%b);
    
}
};
int main(int argc,const char** argv)
{
   Rational r1,r2,r3;
   r1=Rational(-4,5);
   r2=Rational(-16,-32);
   (r1+r2).printRational();

   return 0;
}