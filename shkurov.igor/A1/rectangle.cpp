#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t& pos, const double height, const double width):
  center_(pos),
  height_(height),
  width_(width)
{
  assert(height > 0 && width > 0);
}

double Rectangle::getArea() const
{
  return height_ * width_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {height_, width_, center_};
}

void Rectangle::move(const point_t& new_pos)
{
  center_ = new_pos;
}

void Rectangle::move(const double move_x, const double move_y)
{
  center_.x += move_x;
  center_.y += move_y;
}
