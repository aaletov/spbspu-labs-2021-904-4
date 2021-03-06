#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <ostream>
#include <functional>
#include <stdexcept>
#include <cstring>

namespace razukrantov
{
  template < typename T >
  std::function < bool(T, T) > getSortOrder(const char* order)
  {
    if (order == nullptr)
    {
      throw(std::invalid_argument("Incorrect order\n"));
    }
    if (!strcmp(order, "ascending"))
    {
      return std::greater< T >();
    }
    if (!strcmp(order, "descending"))
    {
      return std::less< T >();
    }
    throw(std::invalid_argument("Incorrect order\n"));
  }

  template < typename Strategy, typename T >
  void print(const typename Strategy::container& container, std::ostream& out, const char* delimiter)
  {
    typename Strategy::constIterator begin = Strategy::begin(container);
    typename Strategy::constIterator size = Strategy::end(container);
    for (typename Strategy::constIterator i = begin; i != size; i++)
    {
      out << Strategy::get(container, i) << delimiter;
    }
  }

  void fillRandom(double* array, int size);
  bool isNumber(const char* str);
}

#endif
