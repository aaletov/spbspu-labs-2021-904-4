#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP

#include <string>
#include <iosfwd>

namespace ezerinia {
  struct DataStruct {
    int key1;
    int key2;
    std::string str;
  };
  bool operator<(const DataStruct &lhs, const DataStruct &rhs);
  std::ostream &operator<<(std::ostream &out, const ezerinia::DataStruct &data);
  std::istream &operator>>(std::istream &in, ezerinia::DataStruct &data);
}

#endif
