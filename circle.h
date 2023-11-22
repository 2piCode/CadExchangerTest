#pragma once
#include <cmath>

#include "curve_3d.h"
#include "point_3d.h"

class circle final : curve_3d {
  point_3d center_;
  double radius_;
public:
    circle(const double radius) : circle({0, 0, 0}, radius) {}

    circle(const point_3d &center, const double radius) : center_(center),
      radius_(radius) {}

    double get_radius() const { return radius_; }

    point_3d derivative(double t) override {
      return point_3d{-radius_ * std::sin(t), radius_ * std::cos(t), 0};
    }
};
