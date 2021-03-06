#include "task-file.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "iterator-print.hpp"

namespace shilyaev {
  const size_t INITIAL_CAPACITY = 1024;
  const size_t CAPACITY_INCREASE_FACTOR = 2;

  std::tuple< std::unique_ptr< char[] >, size_t > read(std::ifstream &ifstream)
  {
    size_t capacity = INITIAL_CAPACITY;
    std::unique_ptr< char[] > fileContent = std::make_unique< char[] >(capacity);
    size_t size = 0;
    while (ifstream.good()) {
      ifstream.read(fileContent.get() + size, capacity - size);
      size += ifstream.gcount();
      capacity *= CAPACITY_INCREASE_FACTOR;
      std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
      for (size_t j = 0; j < size; j++) {
        temp[j] = fileContent[j];
      }
      fileContent = std::move(temp);
    }
    return std::make_tuple(std::move(fileContent), size);
  }

  int taskFile(int argc, char **argv)
  {
    if (argc != 3) {
      std::cerr << "Filename not specified";
      return 1;
    }
    std::ifstream ifstream(argv[2]);
    if (!ifstream) {
      std::cerr << "File not open";
      return 1;
    }
    std::tuple< std::unique_ptr< char[] >, size_t > readResult = read(ifstream);
    std::unique_ptr< char[] > fileContent = std::move(std::get< 0 >(readResult));
    size_t size = std::get< 1 >(readResult);
    ifstream.close();
    std::vector< char > vector(fileContent.get(), fileContent.get() + size);
    print(vector.cbegin(), vector.cend(), std::cout, "", "");
    return 0;
  }

}
