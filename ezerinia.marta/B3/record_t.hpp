#ifndef RECORD_T_HPP
#define RECORD_T_HPP

#include <iostream>

namespace ezerinia {
  struct record_t {
    std::string number;
    std::string name;
  };
}

std::istream &operator>>(std::istream &in, ezerinia::record_t &src);
std::ostream &operator<<(std::ostream &out, const ezerinia::record_t &src);

#endif
