#include "Helix.h"

#include <stdexcept>
#include <numbers>

Point3D Helix::GetPointAt(Real theParameter)
{
  Real aCoordX = std::cosf(theParameter) * GetRadius();
  Real aCoordY = std::sinf(theParameter) * GetRadius();
  Real aCoordZ = myStep * theParameter / ( 2.0f * std::numbers::pi_v<Real>);
  return Point3D{ aCoordX, aCoordY, aCoordZ };
}

Vector3D Helix::GetFirstDerivativeAt(Real theParameter)
{
  if constexpr (toForceNumericCalc)
  {
    return Curve3D::GetFirstDerivativeAt(theParameter);
  }

  const Point3D aPoint = GetPointAt(theParameter);
  // z(t) = (0.5 * Step * InvPi) * t     z'(t) = 0.5 * Step * InvPi = const
  const Real aConstZRate = myStep / (2.0f * std::numbers::pi_v<Real>);
  // For X and Y component explanation see also Circle::GetFirstDerivativeAt()
  return Vector3D{ -aPoint.Y(), aPoint.X(), aConstZRate };
}

Helix::Helix(Real theRadius, Real theStep)
{
  if (theRadius < 0.0f || theStep < 0.0f)
  {
    throw std::invalid_argument{ "Radius or step of helix can not be negative." };
  }

  myRadius = theRadius;
  myStep = theStep;
}
