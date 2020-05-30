#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class point{
   double x,y;
  public:
    void set(double a,double b)
    {
      x=a;
      y=b;
    }
    friend double Distance(point ob1,point ob2)
    {
      return sqrt((ob1.x-ob2.x)*(ob1.x-ob2.x)+(ob1.y-ob2.y)*(ob1.y-ob2.y));
    }
};
int main(void)
{
  double a1,a2,b1,b2;
  cin>>a1>>a2>>b1>>b2;
  point ob1,ob2;
  ob1.set(a1,a2);
  ob2.set(b1,b2);
  cout<<setiosflags(ios::fixed);
  cout<<setprecision(2)<<Distance(ob1,ob2);
}
