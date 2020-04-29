#include<iostream>

class Rectangle{
  double width,height;
public:
  Rectangle()
  {
    width = 1;
    height = 1;
  }
  Rectangle(double x,double y)//有参构造函数 
	{
		width=x;
		height=y;
	}
  void getArea()
  {
    std::cout << width*height << std::endl;
  }
  void getPerimeter()
  {
    std::cout << 2*(width + height) << std::endl;
  }
};

int main()
{
  double x,y;
  std::cin >> x >> y;
  Rectangle r1(x,y);
  r1.getArea();
  r1.getPerimeter();
  return 0;
}
