#include "BasePoint3D.h"

BasePoint3D::BasePoint3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

double BasePoint3D::x() const { return _x; }
double BasePoint3D::y() const { return _y; }
double BasePoint3D::z() const { return _z; }