#include "Circle.h"
#include "Ellips.h"
#include "Helix.h"

#include <iostream>
#include <memory>
#include <numbers>

int main()
{
  const Real PI = std::numbers::pi_v<Real>;

  {
    auto aCirclePtr = std::make_shared<Circle>(1.0f);
    Real aRadius = aCirclePtr->GetRadius();
    std::shared_ptr<Curve3D> aCircleBasePtr = aCirclePtr;

    Point3D aPnt = aCircleBasePtr->GetPointAt(PI / 5.0f);
    Vector3D aDer = aCircleBasePtr->GetFirstDerivativeAt(PI / 5.0);

    std::cout << "Radius = " << aRadius << "\n";
    std::cout << "Point = " << aPnt << "\n";
    std::cout << "Derivative = " << aDer << "\n\n";
  }

  {
    auto anEllipsPtr = std::make_shared<Ellips>(2.5f, 3.2f);
    Real aRadiusX = anEllipsPtr->GetRadiusX();
    Real aRadiusY = anEllipsPtr->GetRadiusY();
    std::shared_ptr<Curve3D> anEllipsBasePtr = anEllipsPtr;
    Point3D aPnt = anEllipsBasePtr->GetPointAt(PI / 5.0);
    Vector3D aDer = anEllipsBasePtr->GetFirstDerivativeAt(PI / 5.0);

    std::cout << "RadiusX = " << aRadiusX << "\n";
    std::cout << "RadiusY = " << aRadiusY << "\n";
    std::cout << "Point = " << aPnt << "\n";
    std::cout << "Derivative = " << aDer << "\n\n";
  }

  {
    auto aHelixPtr = std::make_shared<Helix>(1.2f, 2.4f);
    Real aRadius = aHelixPtr->GetRadius();
    Real aStep = aHelixPtr->GetStep();
    std::shared_ptr<Curve3D> aHellixBasePtr = aHelixPtr;
    Point3D aPnt = aHellixBasePtr->GetPointAt(PI / 8.0);
    Vector3D aDer = aHellixBasePtr->GetFirstDerivativeAt(PI / 8.0);

    std::cout << "Radius = " << aRadius << "\n";
    std::cout << "Step = " << aStep << "\n";
    std::cout << "Point = " << aPnt << "\n";
    std::cout << "Derivative = " << aDer << "\n\n";
  }

  return 0;
}

