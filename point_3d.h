#pragma once

struct point_3d {
  double x;
  double y;
  double z;

  friend std::ostream &operator<<(std::ostream &os, const point_3d &point) {
    std::cout << "X " << point.x << " Y " << point.y << " Z " << point.z << std::endl;
    return os;
  }
};
