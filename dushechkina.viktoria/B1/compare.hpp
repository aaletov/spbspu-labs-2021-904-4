#ifndef B1_COMPARE_HPP
#define B1_COMPARE_HPP

#include <functional>
#include <stdexcept>
#include <string>
#include <cstring>
#include "strategy.hpp"

namespace dushechkina
{
  template< class T >
  std::function< bool(const T, const T) > getSortingOrder(const char* order)
  {
    if (order == nullptr)
    {
      throw std::invalid_argument("Sorting order is undefined");
    }
    if (!strcmp(order, "ascending"))
    {
      return std::less< const T >();
    }
    if (!strcmp(order, "descending"))
    {
      return std::greater< const T >();
    }
    throw std::invalid_argument("Sorting order is incorrect");
  }
}
#endif
