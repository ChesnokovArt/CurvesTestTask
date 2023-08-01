#pragma once

#include "Curve3D.h"

class Helix : public Curve3D
{
public:

  virtual Point3D GetPointAt(float theParameter) override;

  virtual Vector3D GetFirstDerivativeAt(float theParameter) override;

public:
  Helix(Real theRadius, Real theStep);

  Real GetRadius() const
  {
    return myRadius;
  }

private:
  Real myRadius;
  Real myStep;
};
