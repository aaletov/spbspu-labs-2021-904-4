#include "tools.hpp"

#include <sstream>
#include <string>
#include <iostream>

std::istream& murzakanov::readName(std::istream& in, std::string& name)
{
  name.clear();
  in >> std::ws;
  if (in.get() != '"')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  while (!in.eof())
  {
    char next = in.get();
    if (in.good())
    {
      if (next == '\\')
      {
        name += in.get();
      }
      else if (next != '"')
      {
        name += next;
      }
      else
      {
        break;
      }
    }
    else
    {
      in.setstate(std::ios_base::failbit);
    }
  }
  return in;
}

bool murzakanov::checkIsNum(const std::string& number)
{
  for (size_t i = 0; i < number.length(); i++)
  {
    if (!std::isdigit(number[i]))
    {
      return false;
    }
  }
  return true;
}

bool murzakanov::checkIsSpace(const std::string& arg)
{
  return (arg.find(' ') != std::string::npos);
}

void murzakanov::invalidBookmark(std::ostream& out)
{
  out << "<INVALID BOOKMARK>\n";
}

void murzakanov::empty(std::ostream& out)
{
  out << "<EMPTY>\n";
}

void murzakanov::invalidCommand(std::ostream& out)
{
  out << "<INVALID COMMAND>\n";
}

void murzakanov::invalidStep(std::ostream& out)
{
  out << "<INVALID STEP>\n";
}