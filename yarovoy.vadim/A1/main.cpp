#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void print(const Shape& scr)
{
  std::cout << "Shape: " << scr.getName() << "\n";
  std::cout << "Position: " << "(" << scr.getFrameRect().pos.x
            << ", " << scr.getFrameRect().pos.y << ")" << "\n";
  std::cout << "Area: " << scr.getArea()<< "\n";
}

int main()
{
  Shape* rectangle1 = new Rectangle(1, 2, { 3, 5 });
  print(*rectangle1);
  rectangle1->move(1, 2);
  print(*rectangle1);
  delete rectangle1;

  Shape* circle1 = new Circle(5.25, { 13, -12 });
  print(*circle1);
  circle1->move(2, 1);
  print(*circle1);
  delete circle1;

  return 0;
}
