#include "Circle.h"

#include <cmath>
#include <limits>
#include <stdexcept>

Point3D Circle::GetPointAt(Real theParameter)
{
  Real aCoordX = std::cosf(theParameter) * GetRadius();
  Real aCoordY = std::sinf(theParameter) * GetRadius();
  return Point3D{ aCoordX, aCoordY, 0.0f };
}

Vector3D Circle::GetFirstDerivativeAt(Real theParameter)
{
  if constexpr (toForceNumericCalc)
  {
    return Curve3D::GetFirstDerivativeAt(theParameter);
  }

  // x(t) = R*cos(t)      x'(t) = -R*sin(t) = -y(t)
  // y(t) = R*sin(t)      y'(t) =  R*cos(t) =  x(t)
  // z(t) = const         z'(t) = 0
  // So we can reuse GetPointAt():
  const Point3D aPoint = GetPointAt(theParameter);
  return Vector3D{ -aPoint.Y(), aPoint.X(), 0 };
}

Circle::Circle(Real theRadius)
{
  if (theRadius < 0.0f)
  {
    throw std::invalid_argument{ "Radius of circle can not be negative." };
  }

  myRadius = theRadius;
}
