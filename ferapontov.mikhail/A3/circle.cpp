#include "circle.hpp"
#include <cassert>

const double PI = 3.1415926;

ferapontov::Circle::Circle(double radius, const point_t& pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0 && "Incorrect radius");
}

std::string ferapontov::Circle::getName() const
{
  return "Circle";
}

double ferapontov::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

ferapontov::rectangle_t ferapontov::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void ferapontov::Circle::move(const point_t& pos)
{
  pos_ = pos;
}

void ferapontov::Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void ferapontov::Circle::doScale(const double k)
{
  radius_ *= k;
}

std::unique_ptr< ferapontov::Shape > ferapontov::Circle::clone() const
{
  return std::make_unique< Circle >(*this);
}
