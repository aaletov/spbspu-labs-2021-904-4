#include "tasks.hpp"
#include <stdexcept>
#include <fstream>
#include <vector>
#include <memory>
#include "functions.hpp"

void lebedeva::doTask2(char* argv[], std::ostream& out)
{
  char* fileName = argv[2];
  if (fileName == nullptr)
  {
    throw std::invalid_argument("Invalid file name\n");
  }
  std::ifstream inFile;
  inFile.open(fileName);
  if (!inFile.is_open())
  {
    throw std::runtime_error("Opening file failed\n");
  }

  size_t capacity = 1;
  size_t size = 0;
  std::unique_ptr< char[] > data = std::make_unique< char[] >(capacity);
  while (inFile)
  {
    inFile.read(data.get() + size, capacity - size);
    size += inFile.gcount();
    capacity *= 2;
    std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
    for (size_t i = 0; i < size; i++)
    {
      temp[i] = data[i];
    }
    data = std::move(temp);
  }
  inFile.close();

  std::vector< char > resVec(data.get(), data.get() + size);
  print(resVec, out, "", 0);
}
