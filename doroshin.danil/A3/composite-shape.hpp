#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace doroshin
{
  class CompositeShape: public Shape
  {
  public:
    // Empty CompositeShape is forbidden
    CompositeShape() = delete;
    CompositeShape(const CompositeShape&);
    CompositeShape(CompositeShape&&) noexcept = default;

    // For any type T in Shapes the following must be true:
    // std::is_convertible< shape.copy(), ShapePtr >::value
    template< typename... Shapes >
    CompositeShape(Shapes...);

    ~CompositeShape() override = default;

    CompositeShape& operator=(const CompositeShape&);
    CompositeShape& operator=(CompositeShape&&) noexcept = default;

    void swap(CompositeShape& lhs) noexcept;
    std::unique_ptr< Shape > copy() const override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t vec, bool absolute = false) override;
  private:
    using ShapePtr = std::unique_ptr< Shape >;
    using ShapeArray = std::unique_ptr< ShapePtr[] >;

    ShapeArray shapes_;
    size_t size_;

    void scaleImpl(udouble_t s) override;
  };

  namespace details
  {
    // Constructs a unique_ptr-managed array of T (std::unique_ptr< T[] >)
    // From moved argument values.
    template< typename T, typename... Args >
    std::unique_ptr< T[] > makeUniqueArray(Args&&... args) noexcept
    {
      return std::unique_ptr< T[] >(new T[sizeof...(Args)] { std::move_if_noexcept(args)... });
    }
  }

  template< typename... Shapes >
  CompositeShape::CompositeShape(Shapes... shapes):
    shapes_(details::makeUniqueArray< ShapePtr >( shapes.copy()... )),
    size_(sizeof...(Shapes))
  {
    static_assert(sizeof...(Shapes) > 0, "An empty CompositeShape is illegal");
  }

  void swap(CompositeShape& lhs, CompositeShape& rhs) noexcept;
}

#endif // COMPOSITE_SHAPE_HPP
