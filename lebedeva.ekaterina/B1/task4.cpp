#include "tasks.hpp"
#include <vector>
#include "functions.hpp"
#include "sort.hpp"

void lebedeva::doTask4(char* argv[], std::ostream& out)
{
  int size = 0;
  size = std::atoi(argv[3]);
  if (size <= 0)
  {
    throw std::invalid_argument("Invalid size\n");
  }

  std::vector< double > inVec(size);
  fillRandom(inVec.data(), size);
  std::vector< double > dVec(inVec);

  std::function< bool(double, double) > comp = getSortOrder< double >(argv[2]);
  sort< atAccess >(dVec, comp);

  print(inVec, out, " ", 1);
  print(dVec, out, " ", 1);
}
