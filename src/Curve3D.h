#pragma once

#include "Export.h"
#include "Vector3D.h"

class CURVES_API Curve3D
{
public:
  virtual ~Curve3D() = default;

public:

  virtual Point3D GetPointAt(Real theParameter) = 0;

  // The basic implementation using numeric calculations.
  // Should be overridden in concrete classes if a better approach is found.
  // If toForceNumericCalc is set to true please call implementation of this class.
  virtual Vector3D GetFirstDerivativeAt(Real theParameter);

protected:
  // Use to force using of base class GetFirstDerivativeAt() implementation.
  static constexpr bool toForceNumericCalc = false;

};
