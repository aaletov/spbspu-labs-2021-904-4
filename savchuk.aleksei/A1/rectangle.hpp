#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t& pos, double width, double height);
  ~Rectangle() = default;

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(double dx, double dy) override;

private:
  rectangle_t rect_;
};

#endif
