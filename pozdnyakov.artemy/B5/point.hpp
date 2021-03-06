#ifndef POINT_HPP
#define POINT_HPP

#include <vector>

namespace pozdnyakov
{
  struct Point
  {
    int x, y;
  };
  using Shape = std::vector< Point >;
}

#endif
