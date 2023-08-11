#ifndef CURVES3D_VECTOR_H
#define CURVES3D_VECTOR_H

#include <iostream>
#include <vector>

namespace curves {

  class Vector3 {
    double x, y, z;

  public:
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3() : x(0), y(0), z(0) {}

    Vector3 operator+(const Vector3 &v) const {
      return {x + v.x, y + v.y, z + v.z};
    }

    Vector3 operator-(const Vector3 &v) const {
      return {x - v.x, y - v.y, z - v.z};
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector3 &p) {
      os << "<" << p.x << ", " << p.y << ", " << p.z << ">";
      return os;
    }
  };

}// namespace curves

#endif//CURVES3D_VECTOR_H
