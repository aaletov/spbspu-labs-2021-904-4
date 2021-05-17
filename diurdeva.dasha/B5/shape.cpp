#include "shape.hpp"
#include <sstream>
#include <iterator>

const int TRIANGLE_TOPS = 3;
const int QUADRANGLE_TOPS = 4;
const int PENTAGON_TOPS = 5;

std::istream& diurdeva::operator>>(std::istream& in, Shape& shape)
{
  unsigned int numberOfVertices = 0;
  in >> numberOfVertices;
  char point = '\n';
  in >> std::noskipws >> point;
  if (point == '\n') {
    throw std::runtime_error("Error read");
  }
  std::string str;
  in >> std::skipws;
  std::getline(in, str);
  if (str.empty()) {
    return in;
  }
  std::istringstream input(str);
  Shape shapeTemp;
  shapeTemp.reserve(numberOfVertices);
  std::istream_iterator< Point > istream_iter(input);
  std::istream_iterator< Point > istream_iter_end;
  std::copy(istream_iter, istream_iter_end, std::back_inserter(shapeTemp));
  if ((!input && !input.eof()) || numberOfVertices != shapeTemp.size() || shapeTemp.size() < 3) {
    throw std::runtime_error("Error read");
  }
  shape.swap(shapeTemp);
  return in;
}

std::ostream& diurdeva::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out, " "));
  return out;
}

diurdeva::ShapeType diurdeva::getType(const Shape& shape)
{
  const int size = shape.size();
  switch (size)
  {
  case TRIANGLE_TOPS:
    return TRIANGLE;
  case QUADRANGLE_TOPS:
  {
    const int s1 = squareDistance(shape.at(0), shape.at(1));
    const int s2 = squareDistance(shape.at(0), shape.at(2));
    const int s3 = squareDistance(shape.at(0), shape.at(3));
    const int s4 = squareDistance(shape.at(1), shape.at(2));
    const int s5 = squareDistance(shape.at(1), shape.at(3));
    const int s6 = squareDistance(shape.at(2), shape.at(3));
    if (s1 == s6 && s3 == s4 && s2 == s5)
    {
      if (2 * s1 == s2 || 2 * s2 == s1 || 2 * s1 == s3)
      {
        return SQUARE;
      }
      return RECTANGLE;
    }
    return DEFAULT;
  }
  case PENTAGON_TOPS:
    return PENTAGON;
  default:
    return DEFAULT;
  }
}

bool diurdeva::isTriangle(const Shape& shape)
{
  return getType(shape) == TRIANGLE;
}

bool diurdeva::isRectangle(const Shape& shape)
{
  return getType(shape) == RECTANGLE;
}

bool diurdeva::isSquare(const Shape& shape)
{
  return getType(shape) == SQUARE;
}

bool diurdeva::isPentagon(const Shape& shape)
{
  return getType(shape) == PENTAGON;
}
