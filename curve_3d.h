#pragma once
#include "point_3d.h"

class curve_3d {
 protected:
  point_3d center_;
 public:
  curve_3d() : curve_3d(point_3d{0, 0, 0}) {}
  curve_3d(point_3d const &center) : center_(center) {}

  virtual ~curve_3d() = default;
  virtual void print_type() const { std::cout << "Curve" << std::endl; }
  virtual point_3d get_coordinate(double t) const { return point_3d{0, 0, 0}; }
  virtual point_3d derivative(double t) { return point_3d{0, 0, 0}; }
};
