#pragma once

#include "Curve3D.h"

class CURVES_API Helix : public Curve3D
{
public:

  virtual Point3D GetPointAt(Real theParameter) override;

  virtual Vector3D GetFirstDerivativeAt(Real theParameter) override;

public:
  Helix(Real theRadius, Real theStep);

  Real GetRadius() const
  {
    return myRadius;
  }

  Real GetStep() const
  {
    return myStep;
  }

private:
  Real myRadius;
  Real myStep;
};
