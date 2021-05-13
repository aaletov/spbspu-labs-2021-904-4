#include "user-interface.hpp"

#include <ostream>
#include <stdexcept>
#include <cstdlib>

#include "phone-book.hpp"
#include "error-messages.hpp"

namespace lab = savchuk;

lab::UserInterface::UserInterface()
{
  bookmarks_.insert(std::make_pair("current", phoneBook_.begin()));
}

void lab::UserInterface::add(const lab::contact_t& contact)
{
  phoneBook_.add(contact);
  if (phoneBook_.size() == 1)
  {
    bookmarks_["current"] = phoneBook_.begin();
  }
}

void lab::UserInterface::store(const std::string& markName, const std::string& newMarkName)
{
  checkMark(markName);
  bookmarks_.insert(std::make_pair(newMarkName, bookmarks_[markName]));
}

void lab::UserInterface::insertBefore(const std::string& markName, const contact_t& contact)
{
  // checkMark(markName);
  if (markName == "current" && phoneBook_.empty())
  {
    add(contact);
    return;
  }
  phoneBook_.add(bookmarks_[markName], contact);
}

void lab::UserInterface::insertAfter(const std::string& markName, const contact_t& contact)
{
  // checkMark(markName);
  if (markName == "current" && phoneBook_.empty())
  {
    add(contact);
    return;
  }
  PhoneBook::iterator it = bookmarks_[markName];
  phoneBook_.add(++it, contact);
}

void lab::UserInterface::remove(const std::string& markName)
{
  checkMark(markName);
  PhoneBook::iterator it1 = bookmarks_[markName];
  PhoneBook::iterator it2 = phoneBook_.remove(it1);
  if (it2 == phoneBook_.end())
  {
    it2 = phoneBook_.begin();
  }
  for (std::pair< const std::string, PhoneBook::iterator >& mark: bookmarks_)
  {

    if (mark.second == it1)
    {
      mark.second = it2;
    }
  }
}

void lab::UserInterface::show(std::ostream& os, const std::string& markName)
{
  checkMark(markName);
  phoneBook_.show(os, bookmarks_[markName]);
}

void lab::UserInterface::move(const std::string& markName, const std::string& steps)
{
  checkMark(markName);
  if (steps == "first")
  {
    bookmarks_[markName] = phoneBook_.move(bookmarks_[markName], -2 * phoneBook_.size());
  }
  else if (steps == "last")
  {
    bookmarks_[markName] = phoneBook_.move(bookmarks_[markName], 2 * phoneBook_.size());
  }
  else
  {
    bookmarks_[markName] = phoneBook_.move(bookmarks_[markName], std::atoi(steps.c_str()));
  }
}

void lab::UserInterface::checkMark(const std::string& markName)
{
  if (bookmarks_.find(markName) == bookmarks_.end())
  {
    throw std::invalid_argument(INVALID_BOOKMARK);
  }
  if (phoneBook_.empty())
  {
    throw std::invalid_argument(EMPTY);
  }
}
