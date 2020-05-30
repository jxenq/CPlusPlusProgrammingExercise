#include<iostream>
using namespace std;
class Complex
{
 private:
    double real;
    double image;
public:
 Complex()
 {
  real = image = 0;
 }
    Complex(double r, double i)
    {
        real = r;
        image = i;
    }
    void qufan()
    {
     real = -real;
     image = -image;
 }
    void Print()
    {
        cout << "(" << real << ", " << image << ")" << endl;
    }
    Complex operator+(const Complex &t) const
    {
        Complex sum;
        sum.real = real + t.real;
        sum.image = image + t.image;
        return sum;
    }
};
int main()
{
    double r1, i1, r2, i2;
    cin >> r1 >> i1 >> r2 >> i2;
    Complex c1(r1, i1), c2(r2, i2);
    Complex c, _c2;
    c = c1 + c2;
    _c2 = c2;
    c.Print();
    c2.qufan();
    c = c2 + c1;
    c.Print();
    _c2.Print();
}
