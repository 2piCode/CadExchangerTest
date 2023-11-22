#pragma once
#include <cmath>

#include "point_3d.h"
#include "curve_3d.h"

class elipse final : curve_3d{
  point_3d center_;
  double radius_x_;
  double radius_y_;
public:
    elipse(const double radius_x, const double radius_y, const double radius_z)
      : elipse({0, 0, 0}, radius_x, radius_y, radius_z) {}

    elipse(const point_3d &center, const double radius_x, const double radius_y,
           const double radius_z) : center_(center),
      radius_x_(radius_x), radius_y_(radius_y) {}

    double get_radius_x() const { return radius_x_; }
    double get_radius_y() const { return radius_y_; }

    point_3d derivative(double t) override {
        return point_3d{radius_x_ * std::cos(t), radius_y_ * std::sin(t), 0}; 
    }
};
