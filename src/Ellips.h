#pragma once

#include "Curve3D.h"

class Ellips : public Curve3D
{
public:

  virtual Point3D GetPointAt(float theParameter) override;

  virtual Vector3D GetFirstDerivativeAt(float theParameter) override;

public:
  Ellips(Real theRadiusX, Real theRadiusY);

  Real GetRadiusX() const
  {
    return myRadiusX;
  }

  Real GetRadiusY() const
  {
    return myRadiusY;
  }

private:
  Real myRadiusX;
  Real myRadiusY;
};
