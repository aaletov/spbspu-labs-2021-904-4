#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <map>
#include <iosfwd>

#include "phone-book.hpp"

namespace savchuk
{
  class UserInterface
  {
    public:
      UserInterface();

      void add(const contact_t& contact);
      void store(const std::string& markName, const std::string& newMarkName);
      void insertBefore(const std::string& markName, const contact_t& contact);
      void insertAfter(const std::string& markName, const contact_t& contact);
      void remove(const std::string& markName);
      void show(std::ostream& os, const std::string& markName);
      void move(const std::string& markName, const std::string& steps);

    private:
      std::map< std::string, PhoneBook::iterator > bookmarks_;
      PhoneBook phoneBook_;

      void checkMark(const std::string& markName);
  };
}

#endif
