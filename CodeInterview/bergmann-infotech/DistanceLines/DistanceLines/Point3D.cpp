#include "DistanceLines.h"

 double x_, y_, z_;

Point3D::Point3D(double x = 0.0, double y = 0.0, double z = 0.0) : _x(x), _y(y), _z(z) {}

    double Point3D::x() const { return _x; }
    double Point3D::y() const { return _y; }
    double Point3D::z() const { return _z; }


Point3D Point3D::operator+(const Vector3D& other_vec) const {
    return Point3D(_x + other_vec.x(), _y + other_vec.y(), _z + other_vec.z());
}

Vector3D Point3D::operator-(const Point3D& other) const {
    return Vector3D(_x - other._x, _y - other._y, _z - other._z);
}
