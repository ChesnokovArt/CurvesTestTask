#include "Curve3D.h"

Vector3D Curve3D::GetFirstDerivativeAt(Real theParameter)
{
  const int nbULPs = 50;
  const Real anEpsilon = std::numeric_limits<Real>::epsilon() * std::fabs(theParameter) * nbULPs;
  const Real aLeftProbeParam = theParameter - anEpsilon;
  const Real aRightProbeParam = theParameter + anEpsilon;

  const Point3D aLeftProbe = GetPointAt(aLeftProbeParam);
  const Point3D aRightProbe = GetPointAt(aRightProbeParam);
  Vector3D aResult = (aRightProbe - aLeftProbe) / (2 * anEpsilon);
  return aResult;
}
