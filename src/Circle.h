#pragma once

#include "Curve3D.h"

class CURVES_API Circle : public Curve3D
{
public:

  virtual Point3D GetPointAt(Real theParameter) override;

  virtual Vector3D GetFirstDerivativeAt(Real theParameter) override;

public:
  Circle(Real theRadius);

  Real GetRadius() const
  {
    return myRadius;
  }

private:
  Real myRadius;
};
