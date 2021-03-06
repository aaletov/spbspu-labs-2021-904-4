#include "tools.hpp"
#include "random-engine.hpp"

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <random>

namespace lab = savchuk;

size_t lab::convertToNumber(const char* str)
{
  size_t len = strlen(str);
  if (len == 0)
  {
    throw std::runtime_error("invalid number format");
  }
  for (size_t i = 0; i < len; ++i)
  {
    if (!isdigit(str[i]))
    {
      throw std::runtime_error("invalid number format");
    }
  }
  return std::atoi(str);
}
void lab::fillRandom(double* array, size_t size)
{
  std::uniform_int_distribution<> dist(-10, 10);
  for (size_t i = 0; i < size; ++i)
  {
    array[i] = dist(getRandomEngine()) / 10.0;
  }
}
void lab::removeEvenNumbers(std::vector< int >& vec)
{
  using iterator = typename std::vector< int >::iterator;
  std::vector< int > tmp = vec;
  for (iterator it = tmp.begin(); it != tmp.end();)
  {
    if (*it % 2 == 0)
    {
      it = tmp.erase(it);
    }
    else
    {
      ++it;
    }
  }
  vec.swap(tmp);
}
void lab::addExtraNumbers(std::vector< int >& vec)
{
  using iterator = typename std::vector< int >::iterator;
  std::vector< int > tmp = vec;
  size_t count = 0;
  for (iterator it = tmp.begin(); it != tmp.end(); ++it)
  {
    if (*it % 3 == 0)
    {
      ++count;
    }
  }
  tmp.reserve(tmp.size() + 3 * count);
  for (iterator it = tmp.begin(); it != tmp.end();)
  {
    if (*it % 3 == 0)
    {
      it = tmp.insert(++it, { 1, 1, 1 });
    }
    else
    {
      ++it;
    }
  }
  vec.swap(tmp);
}
