#include "circle.hpp"
#include <cmath>

namespace dan = doroshin;

const double PI = 3.14159265358979323846;

dan::Circle::Circle(point_t pos, udouble_t r):
  pos_(pos),
  radius_(r)
{}

double dan::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

dan::rectangle_t dan::Circle::getFrameRect() const
{
  return rectangle_t{ udouble_t(2 * radius_), udouble_t(2 * radius_), pos_ };
}

void dan::Circle::move(point_t vec, bool absolute)
{
  if (absolute) {
    pos_ = vec;
  }
  else {
    pos_.x += vec.x;
    pos_.y += vec.y;
  }
}

void dan::Circle::scaleImpl(dan::udouble_t s)
{
  radius_ *= s;
}

std::unique_ptr< dan::Shape > dan::Circle::copy() const
{
  return std::make_unique< Circle >(*this);
}
