#include <iostream>
#include <stdexcept>

#include "tasks.hpp"
#include "tools.hpp"

namespace lab = savchuk;

int main(int argc, char** argv)
{
  try
  {
    if (argc == 1)
    {
      throw std::invalid_argument("Invalid command line arguments");
    }
    int task = lab::convertToNumber(argv[1]);
    if (task == 1 && argc == 3)
    {
      lab::doTask1(argv[2]);
    }
    else if (task == 2 && argc == 3)
    {
      lab::doTask2(argv[2]);
    }
    else if (task == 3 && argc == 2)
    {
      lab::doTask3();
    }
    else if (task == 4 && argc == 4)
    {
      lab::doTask4(argv[2], argv[3]);
    }
    else
    {
      throw std::invalid_argument("Invalid command line arguments");
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Internal program error\n" << e.what() << '\n';
    return 2;
  }
}
