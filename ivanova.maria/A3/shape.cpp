#include "shape.hpp"
#include <stdexcept>
#include <cassert>

double ivanova::getWidth(const Shape &source)
{
  return source.getFrameRect().width;
}

double ivanova::getHeight(const Shape &source)
{
  return source.getFrameRect().height;
}

double ivanova::getX(const Shape &source)
{
  return source.getFrameRect().pos.x;
}

double ivanova::getY(const Shape &source)
{
  return source.getFrameRect().pos.y;
}

void ivanova::Shape::scaleNoThrow(double k)
{
  assert(k > 0);
  scaleShape(k);
}

void ivanova::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Invalid argument");
  }
  scaleShape(k);
}
