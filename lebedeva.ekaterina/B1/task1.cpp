#include "tasks.hpp"
#include <vector>
#include <forward_list>
#include <iostream>
#include "functions.hpp"
#include "sort.hpp"

void lebedeva::doTask1(char* argv[], std::istream& in, std::ostream& out)
{
  std::vector< int > brackVec;
  int data = 0;
  while (in >> data)
  {
    brackVec.push_back(data);
  }
  if (in.bad() || (in.fail() && !in.eof()))
  {
    throw std::runtime_error("Invalid input");
  }
  std::function< bool(int, int) > comp = getSortOrder< int >(argv[2]);

  std::vector< int > atVec(brackVec);
  std::forward_list< int > iterList(brackVec.begin(), brackVec.end());

  sort< bracketsAccess >(brackVec, comp);
  sort< atAccess >(atVec, comp);
  sort< iteratorAccess >(iterList, comp);

  print(brackVec, out, " ", 1);
  print(atVec, out, " ", 1);
  print(iterList, out, " ", 1);
}

