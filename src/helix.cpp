#include <cmath>
#include <curves/curves.h>

namespace curves {
  Point Helix::evaluate(double t) const {
    return c.evaluate(t) + Point(0, 0, step * (t / (2 * M_PI)));
  }

  Vector3 Helix::derivative(double t) const {
    return c.derivative(t) + Vector3(0, 0, step);
  }
}// namespace curves