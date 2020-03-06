

#include <iostream>
using namespace std;
void swap (  int &a,  int &b );

int main()
{
     int x, y;
     cin>>x>>y;
     swap(x, y);
     cout<<x<<' '<<y<<endl;
     return 0;
}

void swap ( int &a, int &b )
{
    int t
    t = a;
    a = b;
    b = t;
}
