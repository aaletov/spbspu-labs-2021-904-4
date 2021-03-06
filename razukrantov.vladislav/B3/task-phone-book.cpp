#include "tasks.hpp"

#include <iostream>
#include <algorithm>
#include <sstream>

#include "phone-book.hpp"
#include "phone-book-interface.hpp"
#include "functions.hpp"

void razukrantov::taskPhoneBook(std::istream& in, std::ostream& out)
{
  razukrantov::PhoneBook phoneBook;
  razukrantov::PhoneBookInterface  interface(phoneBook);
  std::string string;
  while (std::getline(in, string))
  {
    std::stringstream input(string);
    std::string command;
    input >> command;
    if (command == "add")
    {
      std::string number;
      input >> number;
      if (!std::all_of(number.begin(), number.end(), ::isdigit))
      {
        razukrantov::invalidCommand(out);
        continue;
      }
      std::string name;
      razukrantov::readName(input, name);
      if (input)
      {
        interface.add({ number, name });
      }
      else
      {
        razukrantov::invalidCommand(out);
      }
    }
    else if (command == "store")
    {
      std::string bookmark;
      std::string newBookmark;
      input >> bookmark >> newBookmark;
      if (!interface.contains(bookmark))
      {
        razukrantov::invalidBookmark(out);
      }
      else
      {
        interface.store(bookmark, newBookmark);
      }
    }
    else if (command == "insert")
    {
      std::string pos;
      std::string bookmark;
      std::string number;
      std::string name;
      input >> pos >> bookmark >> number;
      if (!std::all_of(number.begin(), number.end(), ::isdigit))
      {
        razukrantov::invalidCommand(out);
        continue;
      }
      if (pos != "before" && pos != "after")
      {
        razukrantov::invalidCommand(out);
        continue;
      }
      razukrantov::readName(input, name);
      if (input && interface.contains(bookmark))
      {
        if (pos == "before")
        {
          interface.insertBefore(bookmark, { number, name });
        }
        else if (pos == "after")
        {
          interface.insertAfter(bookmark, { number, name });
        }
      }
      else
      {
        razukrantov::invalidCommand(out);
      }
    }
    else if (command == "delete")
    {
      std::string bookmark;
      input >> bookmark;
      if (!interface.contains(bookmark))
      {
        razukrantov::invalidBookmark(out);
      }
      else
      {
        interface.erase(bookmark);
      }
    }
    else if (command == "show")
    {
      std::string bookmark;
      input >> bookmark;
      if (interface.contains(bookmark))
      {
        if (!interface.empty())
        {
          out << interface.show(bookmark);
        }
        else
        {
          razukrantov::empty(out);
        }
      }
      else
      {
        razukrantov::invalidBookmark(out);
      }
    }
    else if (command == "move")
    {
      std::string bookmark;
      std::string steps;
      input >> bookmark >> steps;
      if (interface.contains(bookmark))
      {
        try
        {
          int step = std::stoi(steps);
          interface.move(bookmark, step);
        }
        catch (const std::invalid_argument&)
        {
          if (steps == "first")
          {
            interface.move(bookmark, steps);
          }
          else if (steps == "last")
          {
            interface.move(bookmark, steps);
          }
          else
          {
            razukrantov::invalidStep(out);
          }
        }
      }
      else
      {
        razukrantov::invalidBookmark(out);
      }
    }
    else
    {
      razukrantov::invalidCommand(out);
    }
  }
}
