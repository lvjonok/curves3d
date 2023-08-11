#include <cmath>
#include <curves/curves.h>

namespace curves {
  Point Circle::evaluate(double t) const {
    return {radius * cos(t), radius * sin(t), 0};
  }

  Vector3 Circle::derivative(double t) const {
    return {-radius * sin(t), radius * cos(t), 0};
  }
};// namespace curves