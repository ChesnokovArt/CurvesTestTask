#pragma once

#include "Vector3D.h"

class Curve3D
{
public:
  virtual ~Curve3D() = default;

public:

  virtual Point3D GetPointAt(float theParameter) = 0;

  virtual Vector3D GetFirstDerivativeAt(float theParameter) = 0;
};
