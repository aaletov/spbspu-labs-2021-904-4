#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace razukrantov
{
  class Container
  {
  public:
    using valueType = unsigned int;
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, valueType >
    {
    public:
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator --(int);
      const valueType& operator*() const;
      const valueType* operator->() const;
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;

    private:
      friend class Container;
      valueType index_;
      valueType value_;
      explicit Iterator(valueType number, unsigned long long value);
    };

    Container() = default;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
  };
}

#endif
