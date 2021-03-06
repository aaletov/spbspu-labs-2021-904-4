#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const Rectangle& src) = default;
  Rectangle(const point_t& pos, double height, double width);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& new_pos) override;
  void move(double x, double y) override;

private:
  point_t center_;
  double height_;
  double width_;
};

#endif
