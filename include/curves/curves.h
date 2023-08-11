#ifndef CURVES3D_CURVES_H
#define CURVES3D_CURVES_H

#include "point.h"
#include "stdexcept"
#include "vector3.h"

namespace curves {

  class Curve {
  public:
    virtual Point evaluate(double t) const = 0;
    virtual Vector3 derivative(double t) const = 0;
    virtual std::string describe() const = 0;
  };

  class Circle : public virtual Curve {
    double radius;

  public:
    explicit Circle(double radius) : radius(radius) {
      if (radius < 0) {
        throw std::invalid_argument("Radius must be positive");
      }
    }

    double getRadius() const {
      return radius;
    }

    Point evaluate(double t) const override;
    Vector3 derivative(double t) const override;

    std::string describe() const {
      return "Circle: radius = " + std::to_string(radius);
    }
  };

  class Ellipse : public virtual Curve {
    double a, b;

  public:
    Ellipse(double a, double b) : a(a), b(b) {
      if (a < 0 || b < 0) {
        throw std::invalid_argument("Semi-axes must be positive");
      }
    }

    Point evaluate(double t) const override;
    Vector3 derivative(double t) const override;


    std::string describe() const {
      return "Ellipse: a = " + std::to_string(a) + ", b = " + std::to_string(b);
    }
  };

  class Helix : public virtual Curve {
    Circle c;
    double step;

  public:
    Helix(double radius, double step) : c(radius), step(step) {
      if (step < 0) {
        throw std::invalid_argument("Step must be positive");
      }
    }

    Point evaluate(double t) const override;
    Vector3 derivative(double t) const override;

    std::string describe() const {
      return "Helix: base: (" + c.describe() + "), step = " + std::to_string(step);
    }
  };

}// namespace curves

#endif//CURVES3D_CURVES_H
