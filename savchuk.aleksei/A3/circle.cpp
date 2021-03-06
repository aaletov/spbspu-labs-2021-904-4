#include "circle.hpp"

#include <cassert>

namespace lab = savchuk;

const double PI = 3.1415926536;

lab::Circle::Circle(const lab::point_t& pos, double radius):
  pos_(pos),
  radius_(radius)
{
  assert(radius > 0 && "The radius must be positive");
}

double lab::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

lab::rectangle_t lab::Circle::getFrameRect() const
{
  return { pos_, 2 * radius_, 2 * radius_ };
}

void lab::Circle::move(const lab::point_t& point)
{
  pos_ = point;
}

void lab::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void lab::Circle::doScale(double scaleFactor)
{
  radius_ *= scaleFactor;
}

std::unique_ptr< lab::Shape > lab::Circle::clone() const
{
  return std::make_unique< Circle >(*this);
}
