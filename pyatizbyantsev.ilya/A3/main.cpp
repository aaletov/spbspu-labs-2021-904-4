﻿#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lab = pyatizbyantsev;
using shapePtr = std::unique_ptr< lab::Shape >;

void printCoordinatesFigure(const lab::Shape& figure)
{
    std::cout << "Now " << figure.getName() << " is located (" << lab::getX(figure)
              << ", " << lab::getY(figure) << ")\n";
}

int main()
{
  std::cout << "Rectangle test:\n";
  lab::point_t posRectangle = {2.2, 8};

  shapePtr figureRectangle(std::make_unique< lab::Rectangle >(lab::Rectangle(6, 8, posRectangle)));
  printCoordinatesFigure(*figureRectangle);

  figureRectangle->move(6, 9);
  printCoordinatesFigure(*figureRectangle);

  std::cout << "Area of rectangle is: " << figureRectangle->getArea() << '\n';

  std::cout << "Circle test:\n";
  lab::point_t posCircle = {1.3, 3.7};

  shapePtr figureCircle(std::make_unique< lab::Circle >(lab::Circle(3, posCircle)));
  printCoordinatesFigure(*figureCircle);

  lab::point_t newPosCircle = {55.55, 66.66};
  figureCircle->move(newPosCircle);
  printCoordinatesFigure(*figureCircle);

  std::cout << "Area of circle is: " << figureCircle->getArea() << '\n';

  std::cout << "Composite Shape test:" << '\n';
  shapePtr composite1(std::make_unique< lab::CompositeShape >(lab::CompositeShape(std::move(figureRectangle), std::move(figureCircle))));
  shapePtr composite2(std::make_unique< lab::CompositeShape >(composite1->clone()));
  printCoordinatesFigure(*composite2);

  composite2->move(3, 0);
  printCoordinatesFigure(*composite2);
  std::cout << "Area of Composite Shape is: " << composite1->getArea() << "\n";

  composite2->scale(3);
  printCoordinatesFigure(*composite2);
  std::cout << "Area of Composite Shape after scale is: " << composite2->getArea() << "\n";

  return 0;
}
