#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "curve_3d.h"
#include "circle.h"
#include "elipse.h"
#include "helix.h"

int generate_random_number(size_t min, size_t max) {
  return std::rand() % max + min;
}

std::vector<curve_3d *> generate_curves() {
  std::vector<curve_3d *> curves;
  for (size_t i = 0; i < 10; i++) {
    auto curve_type = generate_random_number(0, 3);
    auto radius = generate_random_number(1, 10);
    switch (curve_type) {
      case 0: {
        curves.push_back(new circle(radius));
        break;
      }
      case 1: {
        auto radius_y = generate_random_number(1, 10);
        curves.push_back(new elipse(radius, radius_y));
        break;
      }
      case 2: {
        auto step = generate_random_number(1, 10);
        curves.push_back(new helix(radius, step));
        break;
      }
    }
  }

  return curves;
}

void print_curves(std::vector<curve_3d *> curves) {
  for (auto curve : curves) {
    curve->print_type();
    auto coordinates = curve->get_coordinate(M_PI / 4);
    auto derivative = curve->derivative(M_PI / 4);
    std::cout << "Coordinates" << coordinates << std::endl;
    std::cout << "Derivative: " << derivative << std::endl;
  }
}

std::vector<circle*> get_sorted_circles(std::vector<curve_3d *> curves) {
  std::vector<circle *> circles;
  for (auto curve : curves) {
    if (dynamic_cast<circle *>(curve)) {
      circles.push_back(static_cast<circle *>(curve));
    }
  }

  std::sort(circles.begin(), circles.end(), [](circle *a, circle *b) {
    return a->get_radius() < b->get_radius();
  });
  return circles;
}

int main(int argc, char *argv[]) {
  std::srand(std::time(nullptr));

  auto curves = generate_curves();
  print_curves(curves);

  auto circles = get_sorted_circles(curves);
  double radius_sum = 0.0;
  for (auto circle : circles) {
    radius_sum += circle->get_radius();
  }
  std::cout << "Sum radius: " << radius_sum << std::endl;

  for (auto curve : curves) {
    delete curve;
  }

  return 0;
}
