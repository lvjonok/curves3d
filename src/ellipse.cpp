#include <cmath>
#include <curves/curves.h>

namespace curves {
  Point Ellipse::evaluate(double t) const {
    return {a * cos(t), b * sin(t), 0};
  }

  Vector3 Ellipse::derivative(double t) const {
    return {-a * sin(t), b * cos(t), 0};
  }
}// namespace curves