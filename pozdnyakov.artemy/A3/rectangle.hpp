#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace pozdnyakov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double width, double height, point_t center);
    ~Rectangle() override = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void unsafeScale(double coef) override;

  private:
    rectangle_t rec_;
  };

}

#endif
