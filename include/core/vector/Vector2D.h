#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__


#include <iostream>
#include <cmath>

namespace panicengine {


class Vector2D {
 private:
  double x;
  double y;

 public:
  Vector2D(double x = 0.0, double y = 0.0);

  inline void zero() { x = y = 0.0; }

  void normalize();
  void truncate(double max);


  inline double length() const { return sqrt(lengthSq()); }
  inline double lengthSq() const { return x*x + y*y; }
  
  inline Vector2D perp() const { return Vector2D(y, -x); }

  inline double distance(const Vector2D &v) const {
    return (v - *this).length();
  }
  
  inline double distanceSq(const Vector2D &v) const {
    return (v - *this).lengthSq();
  }

  inline Vector2D reverse() const { return Vector2D(-x, -y); }



  ///////////////////// Operators
  
  Vector2D operator+(const Vector2D &v) const;
  const Vector2D& operator+=(const Vector2D &v);
  Vector2D operator-(const Vector2D &v) const;
  const Vector2D& operator-=(const Vector2D &v);
  Vector2D operator-() const;
  Vector2D operator*(const double &d) const;
  const Vector2D& operator*=(const double &d);
  Vector2D operator/(const double &d) const;
  const Vector2D& operator/=(const double &d);

  double operator*(const Vector2D &v) const;

  bool operator==(const Vector2D &v) const;
  bool operator!=(const Vector2D &v) const;
  bool operator!() const;

  friend std::ostream& operator<<(std::ostream &stream, const Vector2D &v);

  friend Vector2D& operator<<(Vector2D &v1, const Vector2D &v2);
};




} // namespace panicengine

#endif
