#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace pyatizbyantsev
{
  class Circle: public Shape
  {
  public:
    Circle(double valueRadius, const point_t& valuePos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::string getName() const override;
    void move(const point_t& newPos) override;
    void move(double abscissa, double ordinate) override;

  private:
    void doScale(double scaleCoefficient) override;
    double radius_;
    point_t pos_;
  };
}

#endif
