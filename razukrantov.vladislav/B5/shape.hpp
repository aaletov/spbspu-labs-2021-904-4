#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iosfwd>

#include "point.hpp"

namespace razukrantov
{
  using Shape = std::vector< Point >;
  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
  bool isTriangle(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isPentagon(const Shape& shape);
}

#endif
