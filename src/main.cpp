#include "Circle.h"
#include "Ellips.h"
#include "Helix.h"

#include <iostream>
#include <iomanip>
#include <memory>
#include <numbers>
#include <numeric>
#include <random>
#include <ranges>

int main()
{
  // Random filling.
  std::random_device aRandDev;
  std::mt19937 anEngine{ aRandDev() };
  std::uniform_int_distribution<int> aCurveTypeGenerator{ 0, 2 };
  std::uniform_real_distribution<Real> aRadiiGenerator{ -0.3f, 4.0f };

  const int nbDesiredCurves = 30;
  using CurvePtr = std::shared_ptr<Curve3D>;
  std::vector<CurvePtr> aFirstContainer;
  for (int aCurrentCurve = 0; aCurrentCurve < nbDesiredCurves; aCurrentCurve++)
  {
    try
    {
      int aType = aCurveTypeGenerator(anEngine);
      switch (aType)
      {
      case 0:
        aFirstContainer.push_back(std::make_shared<Circle>(aRadiiGenerator(anEngine)));
        break;
      case 1:
        aFirstContainer.push_back(std::make_shared<Ellips>(aRadiiGenerator(anEngine), aRadiiGenerator(anEngine)));
        break;
      case 2:
        aFirstContainer.push_back(std::make_shared<Helix>(aRadiiGenerator(anEngine), aRadiiGenerator(anEngine)));
        break;
      default:
        break;
      }
    }
    // Handling physical uncorrectness
    catch (std::invalid_argument anExc)
    {
      std::cout << anExc.what() << "\n";
      aCurrentCurve--;
    }
  }

  // Printing at Pi/4
  const Real aParamOfInterest = std::numbers::pi_v<Real> / 4.0f;
  std::cout << std::fixed << std::setprecision(3);
  for (int anIdx = 0; const auto & aCurve : aFirstContainer)
  {
    std::cout << "Curve #" << anIdx << "'s \tPoint = " << aCurve->GetPointAt(aParamOfInterest)
              << "\tFirst derivative = " << aCurve->GetFirstDerivativeAt(aParamOfInterest) << "\n";

    anIdx++;
  }

  // Filtering
  auto isCircle = [](const auto & theCurve)
  {
    return std::dynamic_pointer_cast<Circle>(theCurve) != nullptr;
  };
  auto anOnlyCirclesView = aFirstContainer | std::views::filter(isCircle);
  std::vector<CurvePtr> aSecondContainer(anOnlyCirclesView.begin(), anOnlyCirclesView.end());

  // Sorting
  std::ranges::sort (aSecondContainer, std::less<>{}, [](const auto& theCircle)
    {
      return std::static_pointer_cast<Circle>(theCircle)->GetRadius();
    });
  for (int anIdx = 0; const auto & aCircle : aSecondContainer)
  {
    std::cout << "Circle #" << anIdx << "'s \tRadius = " << std::static_pointer_cast<Circle>(aCircle)->GetRadius() << "\n";
    anIdx++;
  }

  // Sum of radii sequential
  Real aSum1 = std::reduce(std::next(aSecondContainer.begin()), aSecondContainer.end(),
                           std::static_pointer_cast<Circle>(aSecondContainer[0])->GetRadius(),
                           [](Real theAccumulatedValue, const auto& theCircle)
    {
      return theAccumulatedValue + std::static_pointer_cast<Circle>(theCircle)->GetRadius();
    });
  std::cout << "Sum of radii = " << aSum1 << "\n";

  // TODO:
  //   OpenMP reduce
  //   shared lib

  return 0;
}

