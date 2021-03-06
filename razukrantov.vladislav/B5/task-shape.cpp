#include "tasks.hpp"

#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>

#include "functions.hpp"
#include "shape.hpp"

void razukrantov::shapeTask(std::istream& in, std::ostream& out)
{
  std::vector< Shape > shapes;
  std::copy(std::istream_iterator< Shape >(in), std::istream_iterator< Shape >(), std::back_inserter(shapes));
  if (in.fail() && !in.eof())
  {
    throw std::runtime_error("Incorrect input");
  }
  unsigned int vertices = std::accumulate(shapes.begin(), shapes.end(), 0, razukrantov::sumVertices);
  unsigned int triangles = std::count_if(shapes.begin(), shapes.end(), razukrantov::isTriangle);
  unsigned int rectangles = std::count_if(shapes.begin(), shapes.end(), razukrantov::isRectangle);
  unsigned int squares = std::count_if(shapes.begin(), shapes.end(), razukrantov::isSquare);
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), razukrantov::isPentagon), shapes.end());
  std::vector< Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), razukrantov::getFrontPoint);
  razukrantov::shapesPartition(shapes);
  out << "Vertices: " << vertices << "\n";
  out << "Triangles: " << triangles << "\n";
  out << "Squares: " << squares << "\n";
  out << "Rectangles: " << rectangles << "\n";
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\n" << "Shapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
}
