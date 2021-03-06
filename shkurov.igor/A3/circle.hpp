#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace shkurov
{
  class Circle: public Shape
  {
  public:
    Circle(const Circle& src) = default;
    Circle(const point_t& center, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double x, double y) override;
    const char* getName() const override;
  private:
    point_t center_;
    double radius_;

    void scaleFigure(double k) override;
  };
}

#endif
