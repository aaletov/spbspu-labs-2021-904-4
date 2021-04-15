#include <iostream>
#include <vector>
#include "tasks.hpp"
#include "functions.hpp"

namespace iva = ivanova;

void pushVec(std::vector<int> &vector)
{
  int in;
  while (std::cin >> in)
  {
    if (isdigit(in))
    {
      vector.push_back(in);
    }
    else
    {
      throw std::invalid_argument("Invalid Number In A Middle");
    }
  }
  if (!std::cin.eof())
  {
    throw std::invalid_argument("Invalid character!");
  }
}

int iva::task1(const char *kindOfSort)
{
  if (strcmp(kindOfSort, "ascending") && strcmp(kindOfSort, "descending"))
  {
    std::cerr << ("Invalid Sort Order");
    exit(1);
  }
  if (kindOfSort == nullptr)
  {
    std::cerr << (" Missing Sort Order");
    exit(1);
  }
  std::vector< int > collection;
  pushVec(collection);
  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << ("Reading failed");
    exit(1);
  }
  if (collection.empty())
  {
    return 0;
  }
  std::vector<int> bracketsVector(collection);
  std::forward_list<int> iteratorForwardList(collection.begin(), collection.end());
  sortAndPrint < iva::strategyBrackets < int > > (collection, kindOfSort);
  sortAndPrint <  iva::strategyAt < int > > (bracketsVector, kindOfSort);
  sortAndPrint <  iva::strategyList < int > > (iteratorForwardList, kindOfSort);
  return 0;
}
