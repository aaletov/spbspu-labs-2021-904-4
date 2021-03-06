#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

#include "tasks.hpp"
#include "functions.hpp"
#include "sort.hpp"

void dushechkina::task1(std::function< bool(const int&, const int&) > comparator)
{
  std::vector< int > vector;
  int element = 0;
  while (std::cin >> element)
  {
    vector.push_back(element);
  }
  if (!std::cin.eof())
  {
    throw std::runtime_error("Incorrect input");
  }
  if (vector.empty())
  {
    return;
  }
  std::vector< int > vector1 = vector;
  std::forward_list< int > list(vector.begin(), vector.end());
  dushechkina::sort< dushechkina::Brackets >(vector, comparator);
  dushechkina::sort< dushechkina::At >(vector1, comparator);
  dushechkina::sort< dushechkina::Iterator >(list, comparator);
  dushechkina::print(vector, " ");
  std::cout << "\n";
  dushechkina::print(vector1, " ");
  std::cout << "\n";
  dushechkina::print(list, " ");
}
