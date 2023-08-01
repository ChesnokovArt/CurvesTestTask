#include "Circle.h"

#include <stdexcept>

Point3D Circle::GetPointAt(float theParameter)
{
  return Point3D();
}

Vector3D Circle::GetFirstDerivativeAt(float theParameter)
{
  return Vector3D();
}

Circle::Circle(Real theRadius)
{
  if (theRadius < 0.0f)
  {
    throw std::invalid_argument("Radius of circle can not be negative.");
  }

  myRadius = theRadius;
}
