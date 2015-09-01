#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__


#include <iostream>

namespace core {

namespace vector {


class Vector2D {
 private:
  int x;
  int y;

 public:
  Vector2D(int x = 0, int y = 0);

  Vector2D operator+(const Vector2D &v) const;
  Vector2D operator-(const Vector2D &v) const;
  Vector2D operator-() const;
  bool operator!() const;

  friend std::ostream& operator<<(std::ostream &stream, const Vector2D &v);
};




} // namespace vector

} // namespace core


#endif
