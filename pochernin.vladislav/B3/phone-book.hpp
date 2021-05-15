#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include <list>

#include "note.hpp"

namespace pochernin
{
  class PhoneBook
  {
  public:
    using constIterator = std::list< Note >::const_iterator;

    void add(const Note& note);
    void insertBefore(constIterator iterator, const Note& note);
    void insertAfter(constIterator iterator, const Note& note);
    bool empty() const;
    constIterator begin();
    constIterator end();

  private:
    std::list< Note > data_;
  };
}

#endif
