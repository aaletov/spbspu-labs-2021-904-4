#include "circle.hpp"
#include <cassert>

double const PI = 3.1415;

Circle::Circle(const double radius, const point_t pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius_ >= 0);
}

double Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, pos_ };
}

void Circle::move(const point_t& point)
{
  pos_ = point;
}

void Circle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

std::string Circle::getName() const
{
  return "Circle";
}
