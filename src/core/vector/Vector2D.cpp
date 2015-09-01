#include <core/vector/Vector2D.h>
#include <iostream>

namespace core {

namespace vector {

Vector2D::Vector2D(int x, int y) : x(x), y(y) {}

Vector2D Vector2D::operator+(const Vector2D &v) const {
  return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator-(const Vector2D &v) const {
  return Vector2D(x - v.x, y - v.y);
}

Vector2D Vector2D::operator-() const {
  return Vector2D(-x, -y);
}

bool Vector2D::operator!() const {
  return (x != 0 && y !=0);
}

std::ostream& operator<<(std::ostream &stream, const Vector2D &v) {
  stream << "{"<< v.x  << ", " << v.y << "}";
  return stream;
}

} // namespace vector

} // namespace core
