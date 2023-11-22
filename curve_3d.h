#pragma once
#include "point_3d.h"

class curve_3d {
public:
  virtual ~curve_3d() = default;
  virtual point_3d derivative(double t);
};
