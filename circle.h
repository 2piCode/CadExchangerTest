#pragma once
#include <cmath>

#include "curve_3d.h"
#include "point_3d.h"

class circle final : public curve_3d {
  double radius_;
 public:
  circle(const double radius) : circle({0, 0, 0}, radius) {}
  circle(const point_3d &center, const double radius) : curve_3d(center),
                                                        radius_(radius) {}

  double get_radius() const { return radius_; }

  point_3d get_coordinate(double t) const override {
    return point_3d{radius_ * std::cos(t), radius_ * std::sin(t), 0};
  }

  point_3d derivative(double t) override {
    return point_3d{-radius_ * std::sin(t), radius_ * std::cos(t), 0};
  }

  void print_type() const override { std::cout << "Circle" << std::endl; }
};
