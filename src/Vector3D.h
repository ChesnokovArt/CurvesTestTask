#pragma once

#include "Export.h"

#include <ostream>

using Real = float;

class CURVES_API Vector3D
{
public:
  Vector3D() = default;
  Vector3D(const Vector3D&) = default;
  Vector3D& operator=(const Vector3D&) = default;

  Vector3D(Real theX, Real theY = 0, Real theZ = 0)
    : myX(theX), myY(theY), myZ(theZ) {}

public:
  Real X() const
  {
    return myX;
  }

  Real& X()
  {
    return myX;
  }

  Real Y() const
  {
    return myY;
  }

  Real& Y()
  {
    return myY;
  }

  Real Z() const
  {
    return myZ;
  }

  Real& Z()
  {
    return myZ;
  }

public:

  Vector3D operator+(const Vector3D& theOther) const;
  Vector3D operator-(const Vector3D& theOther) const;

  Vector3D operator*(Real theMul) const;
  Vector3D operator/(Real theDenom) const;

private:

  Real myX = 0;
  Real myY = 0;
  Real myZ = 0;
};

CURVES_API std::ostream& operator<<(std::ostream& theOut, const Vector3D& theVec);

// Point isn't conceptually a vector, but it's sufficient for test task.
using Point3D = Vector3D;
