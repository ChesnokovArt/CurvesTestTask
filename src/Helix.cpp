#include "Helix.h"

#include <stdexcept>

Point3D Helix::GetPointAt(float theParameter)
{
  return Point3D();
}

Vector3D Helix::GetFirstDerivativeAt(float theParameter)
{
  return Vector3D();
}

Helix::Helix(Real theRadius, Real theStep)
{
  if (theRadius < 0.0f || theStep < 0.0f)
  {
    throw std::invalid_argument("Radius or step of helix can not be negative.");
  }

  myRadius = theRadius;
  myStep = theStep;
}
