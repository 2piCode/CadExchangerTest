#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

#include "curve_3d.h"
#include "point_3d.h"

class helix final : public curve_3d {
  double radius_;
  double step_;
 public:
  helix(double const radius, double const step)
      : helix({0, 0, 0}, radius, step) {}
  helix(point_3d const &center, double const radius, double const step)
      : curve_3d(center), radius_(radius), step_(step) {}

  double get_radius() const { return radius_; }
  double get_step() const { return step_; }

  point_3d get_coordinate(double t) const override {
    return point_3d{radius_ * std::cos(t), radius_ * std::sin(t), step_ * t / (2 * M_PI)};
  }

  point_3d derivative(double t) override {
    return point_3d{-radius_ * std::sin(t), radius_ * std::cos(t),
                    step_ / (2 * M_PI)};
  }

  void print_type() const override { std::cout << "Helix" << std::endl; }
};
