#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

namespace lab = ezerinia;

double lab::getSideLength(const Point &p1, const Point &p2)
{
  return sqrt((p1.x - p2.x) ^ 2 - (p1.y - p2.y) ^ 2);
}

bool lab::isSidesEqual(const Shape &shape)
{
  double side = getSideLength(shape[0], shape[shape.size()]);
  for (int i = 0; i < shape.size() - 1; i++) {
    if (getSideLength(shape[i], shape[i + 1]) != side) {
      return false;
    }
  }
  return true;
}

std::istream &operator>>(std::istream &in, lab::Point &point)
{
  in.ignore(256, '(');
  in >> point.x;
  in.ignore(256, ';');
  in >> point.y;
  in.ignore(256, ')');
  return in;
}

std::istream &operator>>(std::istream &in, lab::Shape &shape)
{
  std::string str;
  int nVertices = 0;
  in >> nVertices;
  for (int i = 0; i < nVertices; i++) {
    lab::Point point;
    in >> point;
    shape.push_back(point);
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const lab::Point &point)
{
  out << " (" << point.x << ";" << point.y << ")";
  return out;
}

std::ostream &operator<<(std::ostream &out, const lab::Shape &shape)
{
  out << shape.size() << " ";
  //std::copy(shape.begin(), shape.end(), std::ostream_iterator< lab::Point >(out, " "));
  for (int i = 0; i < shape.size(); i++) {
    out << shape[i] << " ";
  }
  return out;
}
