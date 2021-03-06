#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double width, const double height, const point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  assert(width >= 0 && height >= 0);
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const point_t& point)
{
  pos_ = point;
}

void Rectangle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

std::string Rectangle::getName() const
{
  return "Rectangle";
}
