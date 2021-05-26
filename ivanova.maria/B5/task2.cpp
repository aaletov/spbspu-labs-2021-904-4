#include "task2.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <numeric>

namespace iva = ivanova;

int iva::task2(std::istream &in, std::ostream &out)
{
  if (!in)
  {
    std::cerr << "failed reading";
    exit(1);
  }
  using uint = unsigned int;
  std::vector< Shape > shapes((std::istream_iterator< Shape >(in)), std::istream_iterator< Shape >());
  uint vert = std::accumulate(shapes.begin(), shapes.end(), 0, countVertices);
  uint tri = std::count_if(shapes.begin(), shapes.end(), isTriangle);
  uint sqr = std::count_if(shapes.begin(), shapes.end(), isSquare);
  uint rect = std::count_if(shapes.begin(), shapes.end(), isRect);
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());
  std::vector< Point > points;
  points.reserve(shapes.size());
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), getFront);
  for(auto&& point: shapes)
  {
    points.emplace_back(point.front());
  }
  std::sort(shapes.begin(), shapes.end(), compare);
  out << "Vertices: " << vert << "\n";
  out << "Triangles: " << tri << '\n';
  out << "Squares: " << sqr << '\n';
  out << "Rectangles: " << rect << '\n';
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
  return 0;
}

std::istream &ivanova::operator >>(std::istream &in, Shape &shp)
{
  size_t vertices = 0;
  std::string line;
  std::getline(in >> std::ws, line);
  if (line.empty())
  {
    return in;
  }
  std::istringstream iu;
  std::istringstream iss(line);
  iss >> vertices >> std::skipws;
  if (vertices < 3)
  {
    std::cerr << "invalid input 4";
    exit(1);
  }
  shp.reserve(vertices);
  Shape tmp;
  std::copy(std::istream_iterator< Point >(iss), std::istream_iterator < Point >(), std::back_inserter(tmp));
  if (tmp.size() != vertices)
  {
    std::cerr << "invalid input 3";
    exit(1);
  }
  shp.swap(tmp);
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, const Shape &elem)
{
  out << elem.size();
  std::copy(elem.begin(), elem.end(), std::ostream_iterator< Point >(out));
  return out;
}

bool ivanova::compare(Shape &elem1, Shape &elem2)
{
  if (elem1.size() != elem2.size())
  {
    return elem1.size() < elem2.size();
  }
  if (isRect(elem1) && isRect(elem2))
  {
    if (isSquare(elem1) && (isSquare(elem2)))
    {
      return false;
    }
    return isSquare(elem1) && isRect(elem2);
  }
  return false;
}

int ivanova::countVertices(const ivanova::Shape &shp, unsigned int sum)
{
  sum += shp.size();
  return sum;
}

ivanova::Point ivanova::getFront(const ivanova::Shape &shp)
{
  return shp.front();
}

