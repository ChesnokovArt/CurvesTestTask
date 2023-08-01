#pragma once

#include "Curve3D.h"

class Circle : public Curve3D
{
public:

  virtual Point3D GetPointAt(float theParameter) override;

  virtual Vector3D GetFirstDerivativeAt(float theParameter) override;

public:
  Circle(Real theRadius);

  Real GetRadius() const
  {
    return myRadius;
  }

private:
  Real myRadius;
};
