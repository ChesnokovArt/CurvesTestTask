#include "Ellips.h"

#include <stdexcept>

Point3D Ellips::GetPointAt(float theParameter)
{
  return Point3D();
}

Vector3D Ellips::GetFirstDerivativeAt(float theParameter)
{
  return Vector3D();
}

Ellips::Ellips(Real theRadiusX, Real theRadiusY)
{
  if (theRadiusX < 0.0f || theRadiusY < 0.0f)
  {
    throw std::invalid_argument("Radii of ellips can not be negative.");
  }

  myRadiusX = theRadiusX;
  myRadiusY = theRadiusY;
}
