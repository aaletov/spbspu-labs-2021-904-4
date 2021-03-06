#include "composite-shape.hpp"
#include <limits>
#include <stdexcept>
#include <algorithm>

namespace poz = pozdnyakov;

poz::CompositeShape::CompositeShape(UniqueShapes shapes, int shapesLen):
  shapes_(std::move(shapes)),
  shapesLen_(shapesLen),
  frame_(1, 1, poz::point_t{0, 0})
{
  if (shapes_ == nullptr)
  {
    throw std::invalid_argument("Invalid argument");
  }
  for (int i = 0; i < shapesLen; i++)
  {
    if (shapes_[i] == nullptr)
    {
      throw std::invalid_argument("Invalid argument");
    }
  }
  double minX = std::numeric_limits< double >::min();
  double maxY = std::numeric_limits< double >::max();
  double minY = minX;
  double maxX = maxY;
  area_ = 0;
  for (int i = 0; i < shapesLen; i++)
  {
    minX = std::max(minX, getMinX(shapes_[i]->getFrameRect()));
    maxY = std::max(maxY, getMaxY(shapes_[i]->getFrameRect()));
    minY = std::max(minY, getMinY(shapes_[i]->getFrameRect()));
    maxX = std::max(maxX, getMaxX(shapes_[i]->getFrameRect()));
    area_ += shapes_[i]->getArea();
  }
  double width = (maxX - minX) / 2;
  double height = (maxY - minY) / 2;
  frame_ = poz::Rectangle(width, height, poz::point_t{minX + width, minY + height});
}

double poz::CompositeShape::getArea() const
{
  return area_;
}

poz::rectangle_t poz::CompositeShape::getFrameRect() const
{
  return frame_.getFrameRect();
}

void poz::CompositeShape::move(poz::point_t point)
{
  double dx = point.x - frame_.getFrameRect().pos.x;
  double dy = point.y - frame_.getFrameRect().pos.y;
  frame_.move(point);
  for (int i = 0; i < shapesLen_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void poz::CompositeShape::move(double dx, double dy)
{
  frame_.move(dx, dy);
  for (int i = 0; i < shapesLen_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void poz::CompositeShape::unsafeScale(double coef)
{
  area_ *= coef * coef;
  frame_.unsafeScale(coef);
  poz::point_t newPoint;
  for (int i = 0; i < shapesLen_; i++)
  {
    newPoint = poz::point_t{shapes_[i]->getFrameRect().pos.x * coef, shapes_[i]->getFrameRect().pos.y * coef};
    shapes_[i]->move(newPoint);
    shapes_[i]->unsafeScale(coef);
  }
}
