#ifndef CURVES_POINT_H
#define CURVES_POINT_H

#include <iostream>
#include <vector>

namespace curves {

  class Point {
    double x, y, z;

  public:
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    Point() : x(0), y(0), z(0) {}

    Point operator+(const Point &p) const {
      return {x + p.x, y + p.y, z + p.z};
    }

    Point operator-(const Point &p) const {
      return {x - p.x, y - p.y, z - p.z};
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
      os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
      return os;
    }
  };

}// namespace curves

#endif//CURVES_POINT_H
