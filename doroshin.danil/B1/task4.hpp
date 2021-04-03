#ifndef TASK4_HPP
#define TASK4_HPP

#include <iostream>
#include <iomanip>
#include <memory>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace doroshin
{
  void fillRandom(double* array, size_t size);

  template< typename Cmp >
  void testRandom(const size_t size, Cmp cmp)
  {
    std::unique_ptr< double[] > array = std::make_unique< double[] >(size);
    double* raw_ptr = array.get();
    fillRandom(raw_ptr, size);
    std::cout << std::fixed << std::setprecision(5);
    for(size_t i = 0; i < size; ++i) {
      std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    insert_sort< double, ArrayPtrStrat< double > >(raw_ptr, raw_ptr, raw_ptr + size, cmp);
    for(size_t i = 0; i < size; ++i) {
      std::cout << array[i] << ' ';
    }
    std::cout << '\n';
  }
}

#endif //TASK4_HPP
