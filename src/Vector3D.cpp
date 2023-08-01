#include "Vector3D.h"

std::ostream& operator<<(std::ostream& theOut, const Vector3D& theVec)
{
  theOut << "{" << theVec.X() << ", " << theVec.Y() << ", " << theVec.Z() << "}";
  return theOut;
}
