#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <string>

namespace shilyaev {
  class PhoneBook {
  public:
    struct Entry {
      std::string number;
      std::string name;
    };
    using Iterator = std::list< Entry >::iterator;
    size_t size() const;
    bool empty() const;
    Iterator insert(Iterator iterator, const Entry& entry);
    Iterator pushBack(const Entry& entry);
    Iterator erase(Iterator iterator);
    Iterator begin();
    Iterator end();
  private:
    std::list< Entry > entries_;
  };
}

#endif
