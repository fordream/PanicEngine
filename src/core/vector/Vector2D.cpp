#include <core/vector/Vector2D.h>
#include <iostream>
#include <cmath>

namespace panicengine {

namespace core {

namespace vector {

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}


void Vector2D::zero() {
  x = y = 0.0;
}


double Vector2D::length() const {
  return sqrt(lengthSq());
}

double Vector2D::lengthSq() const {
  return x*x + y*y;
}

void Vector2D::normalize() {
  if (!(*this)) {
    double l = length();
    x /= l;
    y /= l;
  }
}

Vector2D Vector2D::perp() const {
  return Vector2D(y, -x);
}

void Vector2D::truncate(double max) {
  if (lengthSq() > max*max) {
    double l = length();
    x *= max/l;
    y *= max/l;
  }
}

double Vector2D::distance(const Vector2D &v) const {
  return (v - *this).length();
}

double Vector2D::distanceSq(const Vector2D &v) const {
  return (v - *this).lengthSq();
}

Vector2D Vector2D::reverse() const {
  return Vector2D(-x, -y);
}

////////////// Operators


Vector2D Vector2D::operator+(const Vector2D &v) const {
  return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator-(const Vector2D &v) const {
  return Vector2D(x - v.x, y - v.y);
}

Vector2D Vector2D::operator-() const {
  return Vector2D(-x, -y);
}

Vector2D Vector2D::operator*(const double &i) const {
  return Vector2D(x*i, y*i);
}

double Vector2D::operator*(const Vector2D &v) const {
  return x*v.x + y*v.y;
}

bool Vector2D::operator!() const {
  return (x != 0 || y !=0);
}

std::ostream& operator<<(std::ostream &stream, const Vector2D &v) {
  stream << "{"<< v.x  << ", " << v.y << "}";
  return stream;
}

} // namespace vector

} // namespace core

} // namespace panicengine
