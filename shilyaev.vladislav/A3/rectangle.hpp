#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace shilyaev {
  class Rectangle: public Shape {
  public:
    Rectangle(double width, double height, const point_t &pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    std::unique_ptr< Shape > clone() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
  private:
    double width_;
    double height_;
    point_t pos_;
    void scaleInternal(double factor) override;
  };
}

#endif
