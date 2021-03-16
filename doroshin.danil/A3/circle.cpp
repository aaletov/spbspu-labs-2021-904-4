#include "circle.hpp"
#include <cmath>

namespace dan = doroshin;

const double PI = 3.14159265358979323846;

dan::Circle::Circle(point_t pos, double r):
  pos_(pos),
  radius_(r)
{
  if(radius_ < 0)
    throw IncorrectCircle();
}

double dan::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

dan::rectangle_t dan::Circle::getFrameRect() const
{
  return rectangle_t{ 2 * radius_, 2 * radius_, pos_ };
}

void dan::Circle::move(point_t vec, bool absolute)
{
  if(absolute) {
    pos_ = vec;
  }
  else {
    pos_.x += vec.x;
    pos_.y += vec.y;
  }
}

void dan::Circle::scale(double s)
{
  radius_ *= fabs(s);
}

dan::Shape* dan::Circle::copy() const
{
  return new Circle(*this);
}

const char* dan::IncorrectCircle::what() const noexcept
{
  return "Incorrect circle";
}
