#include "DistanceLines.h"

Point3D::Point3D(double x, double y, double z) : BasePoint3D(x, y, z) {}

Point3D Point3D::operator+(const Vector3D& other_vec) const {
    return Point3D(_x + other_vec.x(), _y + other_vec.y(), _z + other_vec.z());
}

Vector3D Point3D::operator-(const Point3D& other) const {
    return Vector3D(_x - other._x, _y - other._y, _z - other._z);
}
