#include "tasks.hpp"
#include <string>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include "sort.hpp"
#include "strategies.hpp"
#include "functions.hpp"

namespace poz = pozdnyakov;

void poz::task1(char* argv[])
{
  const char* ASC = "ascending";
  const char* DESC = "descending";
  std::function< bool(double, double) > compare;
  if (!strcmp(argv[0], ASC))
  {
    compare = std::less< double >();
  }
  else if (!strcmp(argv[0], DESC))
  {
    compare = std::greater< double >();
  }
  else
  {
    throw std::invalid_argument("Wrong argument");
  }
  std::vector< int > vector;
  int n;
  while (std::cin >> n)
  {
    vector.push_back(n);
  }
  if (!std::cin.good() && !std::cin.eof())
  {
    throw std::runtime_error("Invalid input");
  }
  if (vector.size() == 0)
  {
    print(vector, std::cout);
    return;
  }
  std::vector< int > indexVector(vector);
  std::vector< int > atVector(vector);
  std::forward_list< int > list(vector.begin(), vector.end());
  poz::sort< poz::IndexStrategy< int > >(indexVector, compare);
  poz::sort< poz::VectorAtStrategy< int > >(atVector, compare);
  poz::sort< poz::ListStrategy< int > >(list, compare);
  poz::print(indexVector, std::cout);
  poz::print(atVector, std::cout);
  poz::print(list, std::cout);
}
