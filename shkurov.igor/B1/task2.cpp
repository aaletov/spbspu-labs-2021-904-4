#include "tasks.hpp"

#include <fstream>

#include "functions.hpp"

namespace lab = shkurov;

void lab::taskTwo(const char* filename)
{
  std::ifstream file;
  file.open(filename);
  if (!file.is_open())
  {
    throw std::invalid_argument("File with such name is not available.\n");
  }

  size_t strCapacity = 1024;
  size_t sizeOfRead = 0;
  std::unique_ptr< char[] > str(std::make_unique< char[] >(strCapacity));

  while (!file.eof())
  {
    file.read(str.get() + sizeOfRead, strCapacity - sizeOfRead);
    sizeOfRead += file.gcount();

    if (sizeOfRead == strCapacity)
    {
      strCapacity *= 2;
      std::unique_ptr< char[] > temp(std::make_unique< char[] >(strCapacity));

      for (size_t i = 0; i < sizeOfRead; i++)
      {
        temp[i] = str[i];
      }

      str.swap(temp);
    }
  }

  file.close();
  std::vector< char > strVec(str.get(), str.get() + sizeOfRead);
  printContainer(strVec, "");
}
