#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__


#include <iostream>

namespace panicengine {

namespace core {

namespace vector {


class Vector2D {
 private:
  double x;
  double y;

 public:
  Vector2D(double x = 0.0, double y = 0.0);

  void zero();
  double length() const;
  double lengthSq() const;

  void normalize();

  Vector2D perp() const;

  void truncate(double max);

  double distance(const Vector2D &v) const;
  double distanceSq(const Vector2D &v) const;

  Vector2D reverse() const;

  Vector2D operator+(const Vector2D &v) const;
  const Vector2D& operator+=(const Vector2D &v);
  Vector2D operator-(const Vector2D &v) const;
  const Vector2D& operator-=(const Vector2D &v);
  Vector2D operator-() const;
  Vector2D operator*(const double &d) const;
  const Vector2D& operator*=(const double &d);
  Vector2D operator/(const double &d) const;
  const Vector2D& operator/=(const double &d);
  int operator*(const Vector2D &v) const;
  const Vector2D& operator*=(const Vector2D &v);

  bool operator==(const Vector2D &v) const;
  bool operator!=(const Vector2D &v) const;
  bool operator!() const;

  friend std::ostream& operator<<(std::ostream &stream, const Vector2D &v);
};




} // namespace vector

} // namespace core

} // namespace panicengine

#endif
