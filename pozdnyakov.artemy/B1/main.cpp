#include <string>
#include <iostream>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc < 2)
    {
      throw std::invalid_argument("Not enough arguments");
    }
    std::string numbers = "1234";
    if (argv[1][0] == numbers.c_str()[0] && argc == 3)
    {
      task1(argv + 2);
    }
    else if (argv[1][0] == numbers.c_str()[1])
    {
      // do task 2
    }
    else if (argv[1][0] == numbers.c_str()[2])
    {
      // do task 3
    }
    else if (argv[1][0] == numbers.c_str()[3])
    {
     // do task 4
    }
    else
    {
      throw std::invalid_argument("Wrong argument");
    }
  }
  catch(std::exception& exc)
  {
    std::cerr << exc.what();
    return -1;
  }
}
