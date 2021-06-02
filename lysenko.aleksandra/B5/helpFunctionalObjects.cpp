#include "helpFunctionalObjects.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

namespace lysenko
{
  static int getDeltaFromFirstPoint(bool abscissa, const lysenko::Shape& obj, size_t pointNumber)
  {
    if (pointNumber < obj.size())
    {
      if (abscissa)
      {
        return obj[pointNumber].x - obj[0].x;
      }
      return obj[pointNumber].y - obj[0].y;
    }
    throw std::out_of_range("Invalid parameters");
  }

  static double getDistanceFromFirstPoint(const lysenko::Shape& obj, int pointNumber)
  {
    double deltaX = getDeltaFromFirstPoint(0, obj, pointNumber);
    double deltaY = getDeltaFromFirstPoint(1, obj, pointNumber);
    return std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));
  }

  static std::vector< double > getSortedVectOfDistancesFromFirstPoint(const lysenko::Shape& obj)
  {
    if (obj.size() == 4)
    {
      double distance01 = getDistanceFromFirstPoint(obj, 1);
      double distance02 = getDistanceFromFirstPoint(obj, 2);
      double distance03 = getDistanceFromFirstPoint(obj, 3);

      std::vector< double > distances{ distance01, distance02, distance03 };
      std::stable_sort(distances.begin(), distances.end());

      return distances;
    }
    std::vector< double > emptyOne;
    return emptyOne;
  }
}

bool lysenko::isTriangle(const lysenko::Shape& obj)
{
  return (obj.size() == 3);
}

bool lysenko::isRectangle(const lysenko::Shape& obj)
{
  std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);
  return (!(distances.empty()) && (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2))));
}

bool lysenko::isSquare(const lysenko::Shape& obj)
{
  std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);

  return ((isRectangle(obj)) && (distances[0] == distances[1]));

}

bool lysenko::isPentagon(const Shape& obj)
{
  return (obj.size() == 5);
}

void lysenko::shapeSort(std::vector< Shape >& vect)
{
  std::vector< Shape > sortedOne;

  std::copy_if(vect.begin(), vect.end(), std::back_inserter(sortedOne), isTriangle);
  std::vector< Shape >::iterator iter = std::remove_if(vect.begin(), vect.end(), isTriangle);
  vect.erase(iter, vect.end());

  std::copy_if(vect.begin(), vect.end(), std::back_inserter(sortedOne), isSquare);
  iter = std::remove_if(vect.begin(), vect.end(), isSquare);
  vect.erase(iter, vect.end());

  std::copy_if(vect.begin(), vect.end(), std::back_inserter(sortedOne), isRectangle);
  iter = std::remove_if(vect.begin(), vect.end(), isRectangle);
  vect.erase(iter, vect.end());

  std::copy(vect.begin(), vect.end(), std::back_inserter(sortedOne));

  std::swap(sortedOne, vect);
}
