#include "tasks.hpp"
#include <string>
#include <sstream>
#include "phonebook_interface.hpp"
#include "error-messages.hpp"

namespace lebedeva
{
  using constIter = std::map< std::string, lebedeva::PhoneBook::constIter >::const_iterator;
}

void lebedeva::doTask1(std::istream& in, std::ostream& out)
{
  Interface obj;
  std::string str;
  while (std::getline(in, str) && !str.empty())
  {
    if (in.fail())
    {
      throw std::runtime_error("Input error in task 1\n");
    }
    std::stringstream input(str);
    std::string command;
    input >> command;

    if (command == "add")
    {
      record_t recToAdd;
      input >> std::ws >> recToAdd.phoneNumber;
      if (checkNumber(recToAdd.phoneNumber))
      {
        std::getline(input >> std::ws, recToAdd.name);
        if (isName(recToAdd.name))
        {
          extractName(recToAdd.name);
          if (!recToAdd.name.empty())
          {
            obj.add(recToAdd);
          }
          else
          {
            invalidCommand(out);
          }
        }
        else
        {
          invalidCommand(out);
        }
      }
      else
      {
        invalidCommand(out);
      }
    }
    else if (command == "store")
    {
      std::string markName;
      std::string newMarkName;

      input >> std::ws >> markName;
      input >> std::ws >> newMarkName;

      constIter iter = obj.find(markName);
      if (iter != obj.end())
      {
        obj.store(markName, newMarkName);
      }
      else
      {
        invalidCommand(out);
      }
    }
    else if (command == "insert")
    {
      std::string whr;
      std::string markName;
      record_t recToIns;

      input >> std::ws >> whr;
      input >> std::ws >> markName;
      input >> std::ws >> recToIns.phoneNumber;
      std::getline(input >> std::ws, recToIns.name);
      if (isName(recToIns.name))
      {
        extractName(recToIns.name);
        if (!(recToIns.name.empty()) && checkNumber(recToIns.phoneNumber))
        {
          constIter iter = obj.find(markName);
          if (iter != obj.end())
          {
            if (whr == "before")
            {
              obj.insert(Interface::Where::before, markName, recToIns);
            }
            else if (whr == "after")
            {
              obj.insert(Interface::Where::after, markName, recToIns);
            }
            else
            {
              invalidCommand(out);
            }
          }
          else
          {
            invalidCommand(out);
          }
        }
        else
        {
          invalidCommand(out);
        }
      }
      else
      {
        invalidCommand(out);
      }
    }
    else if (command == "delete")
    {
      std::string markName;
      input >> std::ws >> markName;
      constIter iter = obj.find(markName);
      if (iter != obj.end())
      {
        obj.deleteRec(markName);
      }
      else
      {
        invalidCommand(out);
      }
    }
    else if (command == "show")
    {
      std::string markName;
      input >> std::ws >> markName;

      constIter iter = obj.find(markName);
      if (iter != obj.end())
      {
        if (!obj.empty())
        {
          out << *iter->second << '\n';
        }
        else
        {
          empty(out);
        }
      }
      else
      {
        invalidBookmark(out);
      }
    }
    else if (command == "move")
    {
      std::string markName;
      std::string steps;
      input >> std::ws >> markName;
      std::getline(input >> std::ws, steps);

      constIter iter = obj.find(markName);
      if (iter != obj.end())
      {
        if (!(steps.empty()))
        {
          if (checkNumber(steps))
          {
            int iSteps = std::stoi(steps);
            obj.move(markName, iSteps);
          }
          else if (steps == "first")
          {
            obj.move(markName, Interface::Steps::first);
          }
          else if (steps == "last")
          {
            obj.move(markName, Interface::Steps::last);
          }
          else
          {
            invalidStep(out);
          }
        }
        else
        {
          invalidCommand(out);
        }
      }
      else
      {
        invalidCommand(out);
      }
    }
    else
    {
      invalidCommand(out);
    }
  }
}
