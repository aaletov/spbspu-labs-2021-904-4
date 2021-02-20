#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t& centre, const double r);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& pos) override;
  void move(const double dx, const double dy) override;
private:
  point_t centre_;
  double r_;
};
#endif
