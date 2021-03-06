#include <iostream>
#include <cassert>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace dan = doroshin;
using namespace dan::literals;

void printShape(const dan::Shape& s)
{
  std::cout << "Shape: (" << dan::getX(s) << ", " << dan::getY(s)
    << ") area: " << s.getArea() << '\n';
}

bool checkPosition(const dan::Shape& s, const dan::point_t other)
{
  return (dan::getX(s) == other.x) && (dan::getY(s) == other.y);
}

int main()
{
  const dan::point_t move_to{ 2, 10 };

  const dan::point_t p1{ -1, 7 }, p2{ 4, -6 }, p3{ -8, -3 };
  std::unique_ptr< dan::Shape > shapes[] = {
    std::make_unique< dan::Circle >(p1, 3_ud),
    std::make_unique< dan::Rectangle >(2_ud, 5_ud, p2),
    std::make_unique< dan::CompositeShape >(dan::Rectangle(5_ud, 1_ud, p3))
  };

  for(auto&& shape: shapes) {
    printShape(*shape);
    shape->move(move_to, true);
    checkPosition(*shape, move_to);
  }

  return 0;
}
