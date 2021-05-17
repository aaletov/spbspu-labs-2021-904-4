#include "functions.hpp"
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <istream>


std::string ferapontov::read(std::istream& in)
{
  std::string line;
  in >> line;
  if (in.fail() && !in.eof())
  {
    throw std::runtime_error("<INPUT ERROR>");
  }
  return line;
}

std::string ferapontov::readName(std::istream& in)
{
  std::string name;
  in >> std::ws;
  std::getline(in, name);
  if (name.front() != '"' || name.back() != '"' || (name.size() < 2))
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }
  name.pop_back();
  name.erase(0, 1);
  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
  return name;
}

std::string ferapontov::checkMarkName(std::string& markName)
{
  for (char& ch: markName)
  {
    if (!isalpha(ch) && !isdigit(ch) && ch != '-')
    {
      throw std::invalid_argument("<INVALID BOOKMARK>");
    }
  }
  return markName;
}

void ferapontov::checkInsertMode(std::string& mode)
{
  if (mode != "before" || mode != "after")
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }
}

void ferapontov::checkNumber(std::string& num)
{
  if (!std::all_of(num.begin(), num.end(), ::isdigit))
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }
}

bool ferapontov::checkSteps(std::string& steps)
{
  if (steps == "last" || steps == "first" || (std::all_of(steps.begin(), steps.end(), ::isdigit)))
  {
    return true;
  }
  if (steps[0] == '-' && (std::all_of(steps.begin() + 1, steps.end(), ::isdigit)))
  {
    return true;
  }
  return false;
}
