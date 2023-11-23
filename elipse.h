#pragma once
#include <cmath>

#include "point_3d.h"
#include "curve_3d.h"

class elipse final : public curve_3d {
  double radius_x_;
  double radius_y_;
 public:
  elipse(const double radius_x, const double radius_y)
      : elipse({0, 0, 0}, radius_x, radius_y) {}
  elipse(const point_3d &center, const double radius_x, const double radius_y) : curve_3d(center),
                                                                                 radius_x_(radius_x),
                                                                                 radius_y_(radius_y) {}

  double get_radius_x() const { return radius_x_; }
  double get_radius_y() const { return radius_y_; }

  point_3d get_coordinate(double t) const override {
    return point_3d{radius_x_ * std::cos(t), radius_y_ * std::sin(t), 0};
  }

  point_3d derivative(double t) override {
    return point_3d{radius_x_ * std::cos(t), radius_y_ * std::sin(t), 0};
  }

  void print_type() const override { std::cout << "Elipse" << std::endl; }
};
