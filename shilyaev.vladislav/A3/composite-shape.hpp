#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace shilyaev {
  class CompositeShape: public Shape {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape &source);
    CompositeShape& operator=(const CompositeShape &other);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    CompositeShape* clone() const override;
    void move(const point_t &pos) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
    size_t getSize() const;
    void insert(std::unique_ptr< Shape > shape);
  private:
    size_t capacity_;
    size_t size_;
    std::unique_ptr< std::unique_ptr< Shape >[] > shapes_;
    void increaseCapacity();
  };
}

#endif
