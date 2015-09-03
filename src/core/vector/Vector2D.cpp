#include <core/vector/Vector2D.h>
#include <iostream>

namespace panicengine {


Vector2D::Vector2D(double x, double y) : x(x), y(y) {}



void Vector2D::normalize() {
  if (!(*this)) {
    double l = length();
    x /= l;
    y /= l;
  }
}


void Vector2D::truncate(double max) {
  if (max > 0 && lengthSq() > max*max) {
    double l = length();
    x *= max/l;
    y *= max/l;
  }
}


////////////// Operators


Vector2D Vector2D::operator+(const Vector2D &v) const {
  return Vector2D(x + v.x, y + v.y);
}

const Vector2D& Vector2D::operator+=(const Vector2D &v) {
  x += v.x;
  y += v.y;
  return *this;
}

Vector2D Vector2D::operator-(const Vector2D &v) const {
  return Vector2D(x - v.x, y - v.y);
}

const Vector2D& Vector2D::operator-=(const Vector2D &v) {
  x -= v.x;
  y -= v.x;
  return *this;
}

Vector2D Vector2D::operator-() const {
  return Vector2D(-x, -y);
}

Vector2D Vector2D::operator*(const double &d) const {
  return Vector2D(x*d, y*d);
}

const Vector2D& Vector2D::operator*=(const double &d) {
  x *= d;
  y *= d;
  return *this;
}

Vector2D Vector2D::operator/(const double &d) const {
  if (d != 0.0)
    return Vector2D(x/d, y/d);

  return Vector2D(); // TODO throw exception instead ? 
}

const Vector2D& Vector2D::operator/=(const double &d) {
  if (d != 0.0) {
    x /= d;
    y /= d;
  }
  return *this;
}

double Vector2D::operator*(const Vector2D &v) const {
  return x*v.x + y*v.y;
}

bool Vector2D::operator==(const Vector2D &v) const {
  return (x == v.x && y == v.y);
}

bool Vector2D::operator!=(const Vector2D &v) const {
  return !(*this == v);
}

bool Vector2D::operator!() const {
  return (x != 0 || y !=0);
}

std::ostream& operator<<(std::ostream &stream, const Vector2D &v) {
  stream << "{"<< v.x  << ", " << v.y << "}";
  return stream;
}

Vector2D& operator<<(Vector2D &v1, Vector2D &v2) {
  v1 += v2;
  return v1;
}


} // namespace panicengine
