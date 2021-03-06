#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

#include <vector>
#include <forward_list>

namespace pozdnyakov
{
  template < typename T >
  class IndexStrategy
  {
  public:
    using ContType = std::vector< T >;
    using IterType = size_t;
    static size_t begin(const std::vector< T >&)
    {
      return 0;
    }
    static size_t end(const std::vector< T >& cont)
    {
      return cont.size();
    }
    static T& getElem(std::vector< T >& cont, size_t iter)
    {
      return cont[iter];
    }
  };

  template < typename T >
  class VectorAtStrategy
  {
  public:
    using ContType = std::vector< T >;
    using IterType = size_t;
    static size_t begin(const std::vector< T >&)
    {
      return 0;
    }
    static size_t end(const std::vector< T >& cont)
    {
      return cont.size();
    }
    static T& getElem(std::vector< T >& cont, size_t iter)
    {
      return cont.at(iter);
    }
  };

  template < typename T >
  class ListStrategy
  {
  public:
    using ContType = std::forward_list< T >;
    using IterType = typename std::forward_list< T >::iterator;
    static typename std::forward_list< T >::iterator begin(std::forward_list< T >& cont)
    {
      return cont.begin();
    }
    static typename std::forward_list< T >::iterator end(std::forward_list< T >& cont)
    {
      return cont.end();
    }
    static T& getElem(const std::forward_list< T >&, const typename std::forward_list< T >::iterator iter)
    {
      return *iter;
    }
  };
}

#endif
