#include "Circle.h"
#include "Ellips.h"
#include "Helix.h"

#include <iostream>
#include <memory>
#include <numbers>

int main()
{
  Circle aCircle{ 3.5f };
  Ellips anEllips{ 2.0f, 3.4f };
  Helix aHelix{ -2.0, 1.0f };

  std::cout << "sizeof(Circle) = " << sizeof(aCircle) << "\n";
  std::cout << "sizeof(Ellips) = " << sizeof(anEllips) << "\n";
  std::cout << "sizeof(Helix) = "  << sizeof(aHelix) << "\n\n";

  auto aHelixPtr = std::make_shared<Helix>(4.3f, 4.3f);
  Real aRadius = aHelixPtr->GetRadius();
  std::shared_ptr<Curve3D> aHellixBasePtr = aHelixPtr;
  using std::numbers::pi;
  Point3D aPnt = aHellixBasePtr->GetPointAt(pi / 4.0);
  Vector3D aDer = aHellixBasePtr->GetFirstDerivativeAt(pi / 4.0);

  std::cout << "Radius = "     << aRadius << "\n";
  std::cout << "Point = "      << aPnt << "\n";
  std::cout << "Derivative = " << aDer << "\n\n";

  return 0;
}

