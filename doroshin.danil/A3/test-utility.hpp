#include <boost/test/unit_test.hpp>
#include "base-types.hpp"
#include "shape.hpp"

namespace doroshin
{
  void equalSize(const rectangle_t&, const rectangle_t&);

  void testMoveRel(Shape&, point_t);

  void testMoveAbs(Shape&, point_t);

  void testScaleArea(Shape&, udouble_t coeff);
  void testScaleFrame(Shape&, udouble_t coeff);
}
