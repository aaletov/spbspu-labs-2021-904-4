#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <cstring>

namespace pozdnyakov
{
  bool findSpaces(const char* const str);
  template <typename T>
  void print(T& cont, std::ostream& out, std::string separator = " ")
  {
    if (cont.begin() == cont.end())
    {
      out << "Omitted due to size.";
    }
    for (typename T::iterator i = cont.begin(); i != cont.end(); i++)
    {
      out << *i << separator;
    }
    out << '\n';
  }
}

#endif
