#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace ezerinia {
  class Container {
  public:
    using value_type = unsigned int;

    class Iterator;

    Container() = default;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
  };

  class Container::Iterator: public std::iterator< std::bidirectional_iterator_tag, value_type > {
  public:
    Iterator();
    Iterator &operator++();
    Iterator &operator--();
    Iterator operator++(int);
    Iterator operator--(int);
    bool operator==(const Iterator &src) const;
    bool operator!=(const Iterator &src) const;
    const value_type &operator*() const;
    const value_type *operator->() const;
  private:
    friend class Container;

    size_t index_;
    value_type value_;
    Iterator(size_t index, value_type value);
  };

  constexpr Container::value_type getFactorial(size_t index);
}
#endif
