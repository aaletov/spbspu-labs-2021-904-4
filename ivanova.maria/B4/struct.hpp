#ifndef B4_STRUCT_HPP
#define B4_STRUCT_HPP

#include <string>
#include <iosfwd>

namespace ivanova
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };
  std::istream &operator >>(std::istream& in, DataStruct &data);
  std::ostream &operator <<(std::ostream& out, const DataStruct &data);
}
#endif
