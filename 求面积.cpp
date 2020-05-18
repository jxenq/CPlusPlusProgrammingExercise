#include<iostream>
using namespace std;
class R{
    int len,w;
public:
    R(int len,int w);
    int getArea();
};
R::R(int len,int w){
    
    this->len = len;
    this->w = w;
}
int R::getArea(){
    return (this->len)*(this->w);
}
int main(){
    R r1(2,5),r2(3,6);
    cout<<"First Area is "<<r1.getArea()<<endl;
    cout<<"Second Area is "<<r2.getArea()<<endl;
    return 0;
}

