#include "Ellips.h"

#include <stdexcept>

Point3D Ellips::GetPointAt(Real theParameter)
{
  Real aCoordX = std::cosf(theParameter) * GetRadiusX();
  Real aCoordY = std::sinf(theParameter) * GetRadiusY();
  return Point3D{ aCoordX, aCoordY, 0.0f };
}

Vector3D Ellips::GetFirstDerivativeAt(Real theParameter)
{
  if constexpr (toForceNumericCalc)
  {
    return Curve3D::GetFirstDerivativeAt(theParameter);
  }

  // x(t) = RX*cos(t)      x'(t) = -RX*sin(t)
  // y(t) = RY*sin(t)      y'(t) =  RY*cos(t)
  // z(t) = const          z'(t) = 0
  Real aCoordX = -std::sinf(theParameter) * GetRadiusX();
  Real aCoordY =  std::cosf(theParameter) * GetRadiusY();
  return Vector3D{ aCoordX, aCoordY, 0.0f };
}

Ellips::Ellips(Real theRadiusX, Real theRadiusY)
{
  if (theRadiusX < 0.0f || theRadiusY < 0.0f)
  {
    throw std::invalid_argument{ "Radii of ellips can not be negative." };
  }

  myRadiusX = theRadiusX;
  myRadiusY = theRadiusY;
}
