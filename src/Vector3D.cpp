#include "Vector3D.h"

std::ostream& operator<<(std::ostream& theOut, const Vector3D& theVec)
{
  theOut << "{" << theVec.X() << ", " << theVec.Y() << ", " << theVec.Z() << "}";
  return theOut;
}

Vector3D Vector3D::operator-(const Vector3D& theOther) const
{
  return Vector3D{ X() - theOther.X(), Y() - theOther.Y(), Z() - theOther.Z() };
}

Vector3D Vector3D::operator*(Real theMul) const
{
  return Vector3D{ X() * theMul, Y() * theMul, Z() * theMul };
}

Vector3D Vector3D::operator/(Real theDenom) const
{
  return Vector3D{ X() / theDenom, Y() / theDenom, Z() / theDenom };
}

Vector3D Vector3D::operator+(const Vector3D& theOther) const
{
  return Vector3D{ X() + theOther.X(), Y() + theOther.Y(), Z() + theOther.Z() };
}
