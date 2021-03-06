#include "tasks.hpp"
#include "sort.hpp"
#include "strategy.hpp"
#include "functions.hpp"

namespace fer = ferapontov;

void fer::task1(const char* mode)
{
  std::function< bool(int, int) > cmp = getSortMode< int >(mode);

  int number = 0;
  std::vector< int > vec;
  while (std::cin >> number)
  {
    vec.push_back(number);
  }
  if (std::cin.fail() && !(std::cin.eof()))
  {
    std::cerr << "Read Error\n";
    std::exit(2);
  }

  std::vector< int > second_vec(vec);
  std::forward_list< int > list(vec.begin(), vec.end());
  fer::sort< int, fer::index_access< int > >(vec, cmp);
  fer::sort< int, fer::at_access< int > >(second_vec, cmp);
  fer::sort< int, fer::iterator_access< int > >(list, cmp);
  print(vec);
  print(second_vec);
  print(list);
}
