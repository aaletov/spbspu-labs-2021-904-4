#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <memory>
#include <string>

#include "strategies.hpp"

namespace shkurov
{
  template < class Strategy, typename T >
  void selectionSort(typename Strategy::container& cont, std::function< bool(T, T) > cmp)
  {
    using iterator_t = typename Strategy::iterator;
    iterator_t end = Strategy::end(cont);
    iterator_t begin = Strategy::begin(cont);

    for (iterator_t i = begin; i != end; i++)
    {
      iterator_t swapId = i;

      for (iterator_t j = i; j != end; j++)
      {
        if (cmp(Strategy::get(cont, j), Strategy::get(cont, swapId)))
        {
          swapId = j;
        }
      }
      if (Strategy::get(cont, i) != Strategy::get(cont, swapId))
      {
        std::swap(Strategy::get(cont, i), Strategy::get(cont, swapId));
      }
    }
  }

  template < typename T >
  void printContainer(const T& cont, const std::string& separator)
  {
    using iterator_t = typename T::const_iterator;

    for (iterator_t it = cont.begin(); it != cont.end(); it++)
    {
      std::cout << *it << separator;
    }
  }

  template < typename T >
  std::function< bool(T, T) > comparsionMethod(const char* cmd)
  {
    if (!strcmp(cmd, "ascending"))
    {
      return std::less< T >();
    }
    else if (!strcmp(cmd, "descending"))
    {
      return std::greater< T >();
    }

    throw std::invalid_argument("Comparsion method must be either descending or ascending.");
  }

  void fillRandom(double *array, int size);
  bool containsSpaces(const char* str);
  bool isNumber(const char* str);
}

#endif
