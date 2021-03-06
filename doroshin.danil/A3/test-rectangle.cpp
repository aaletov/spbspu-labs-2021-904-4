#include <boost/test/unit_test.hpp>
#include "test-utility.hpp"
#include "rectangle.hpp"

namespace dan = doroshin;
using namespace dan::literals;

struct RectangleTestFixture
{
  RectangleTestFixture():
    rect(3_ud, 4_ud, dan::point_t{ 1, 2 })
  {}

  dan::Rectangle rect;
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, RectangleTestFixture)

BOOST_AUTO_TEST_CASE(test_move)
{
  dan::testMoveRel(rect, { 1, 2 });
  dan::testMoveRel(rect, { -5, 7 });
  dan::testMoveAbs(rect, { 65, -33 });
}

BOOST_AUTO_TEST_CASE(test_scale_area)
{
  dan::testScaleArea(rect, 5_ud);
  dan::testScaleArea(rect, 0.3_ud);
}

BOOST_AUTO_TEST_CASE(test_scale_frame)
{
  dan::testScaleFrame(rect, 16_ud);
  dan::testScaleFrame(rect, 0.01_ud);
}

BOOST_AUTO_TEST_SUITE_END()
