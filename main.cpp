#include "include/curves/curves.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

std::vector<std::shared_ptr<curves::Curve>> generate_curves() {
  std::default_random_engine rand;
  rand.seed(std::chrono::system_clock::now().time_since_epoch().count());

  // create container for curves
  std::vector<std::shared_ptr<curves::Curve>> curves;

  // populate curves with random curves and random parameters
  for (int i = 0; i < 5; ++i) {
    switch (rand() % 3) {
      case 0:
        // generate random circle
        curves.emplace_back(std::make_shared<curves::Circle>(double(rand() % 100) + 0.1));
        break;
      case 1:
        // generate random ellipse
        curves.emplace_back(std::make_shared<curves::Ellipse>(double(rand() % 100) + 0.1, double(rand() % 100) + 0.1));
        break;
      case 2:
        // generate random helix
        curves.emplace_back(std::make_shared<curves::Helix>(double(rand() % 100) + 0.1, double(rand() % 100) + 0.1));
        break;
    }
  }

  return curves;
}

int main() {
  auto curves = generate_curves();

  std::cout << "Curves:" << std::endl;

  // print coordinates of points and derivatives of all curves at t = PI / 4
  for (auto &curve: curves) {
    auto pt = curve->evaluate(M_PI / 4);
    auto der = curve->derivative(M_PI / 4);
    std::cout << curve->describe() << std::endl;
    std::cout << "  Point: " << pt << std::endl;
    std::cout << "  Derivative: " << der << std::endl;
  }

  // create container only for circles from curves
  std::vector<std::shared_ptr<curves::Circle>> circles;
  for (auto &curve: curves) {
    if (dynamic_cast<curves::Circle *>(curve.get())) {
      circles.push_back(std::dynamic_pointer_cast<curves::Circle>(curve));
    }
  }

  // sort circles by ascending radius
  std::sort(circles.begin(), circles.end(), [](auto &a, auto &b) {
    return a->getRadius() < b->getRadius();
  });

  std::cout << "Circles:" << std::endl;
  for (auto &circle: circles) {
    std::cout << circle->describe() << std::endl;
  }

  // compute total sum of radii of all circles
  double sum = 0;
  for (auto &circle: circles) {
    sum += circle->getRadius();
  }

  std::cout << "Sum of radii: " << sum << std::endl;

  return 0;
}
