#include "data-struct.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

namespace lab = savchuk;

std::istream& lab::operator>>(std::istream& is, lab::DataStruct& ds)
{
  std::string data;
  if (getline(is, data))
  {
    std::istringstream ss(data);
    char delim = ',';
    int key1 = readKey(ss, delim);
    int key2 = readKey(ss, delim);
    std::string str = readString(ss);
    if (ss.fail())
    {
      is.setstate(std::ios::failbit);
    }
    else
    {
      ds = { key1, key2, str };
    }
  }
  return is;
}

std::ostream& lab::operator<<(std::ostream& os, const lab::DataStruct& ds)
{
  const char* delim = ", ";
  os << ds.key1 << delim << ds.key2 << delim << ds.str;
  return os;
}

int lab::readKey(std::istream& is, char delim)
{
  int key;
  if (is >> std::ws >> key)
  {
    if (is.get() != delim)
    {
      is.setstate(std::ios::failbit);
    }
    else if (std::abs(key) > 5)
    {
      is.setstate(std::ios::failbit);
    }
  }
  return key;
}

std::string lab::readString(std::istream& is)
{
  std::string str;
  if (is)
  {
    if (!getline(is >> std::ws, str) || str.empty())
    {
      is.setstate(std::ios::failbit);
    }
  }
  return str;
}
