#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace shilyaev {
  class Circle: public Shape {
  public:
    Circle(double radius, const point_t &pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::unique_ptr< Shape > clone() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
  private:
    double radius_;
    point_t pos_;
    void scaleInternal(double factor) override;
  };
}

#endif
