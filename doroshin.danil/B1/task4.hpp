#ifndef TASK4_HPP
#define TASK4_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace doroshin
{
  void fillRandom(double* array, size_t size);

  template< typename Cmp >
  void task4(const size_t size, Cmp cmp)
  {
    std::vector< double > array(size);
    fillRandom(array.data(), array.size());
    std::cout << std::fixed << std::setprecision(5);
    for(double val: array) {
      std::cout << val << ' ';
    }
    std::cout << '\n';
    insert_sort< double, VectorIndexStrat >(array, cmp);
    for(double val: array) {
      std::cout << val << ' ';
    }
    std::cout << '\n';
  }
}

#endif //TASK4_HPP
