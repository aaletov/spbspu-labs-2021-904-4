#include "tasks.hpp"
#include <vector>
#include <iostream>
#include "functions.hpp"
#include "vector-operations.hpp"

namespace poz = pozdnyakov;

void poz::task3()
{
  std::vector< int > vector;
  int n = 0;
  while (std::cin >> n && n != 0)
  {
    vector.push_back(n);
  }
  if ((std::cin.fail() && !std::cin.eof()) || n != 0)
  {
    throw std::runtime_error("Invalid input");
  }
  if (vector.size() != 0)
  {
    if (vector.back() == 1)
    {
      poz::eraseEven(vector);
    }
    else if (vector.back() == 2)
    {
      poz::addOnes(vector);
    }
  }
  poz::print(vector, std::cout);
}
