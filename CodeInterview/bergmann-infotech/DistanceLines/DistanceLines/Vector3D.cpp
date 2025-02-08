#include "DistanceLines.h"

   Vector3D::Vector3D(double x = 0.0, double y = 0.0, double z = 0.0) : _x(x), _y(y), _z(z) {}

    double Vector3D::x() const { return _x; }
    double Vector3D::y() const { return _y; }
    double Vector3D::z() const { return _z; }

    double Vector3D::dot(const Vector3D& other) const {
        return _x * other._x + _y * other._y + _z * other._z;
    }

    Vector3D Vector3D::cross(const Vector3D& other) const {
        return {
	        _y * other._z - _z * other._y,
            _z * other._x - _x * other._z,
            _x * other._y - _y * other._x
        };
    }

    double Vector3D::length() const {
        return std::sqrt(dot(*this));
    }

    Vector3D Vector3D::normalize() const {
        double len = length();
        if (len == 0.0) throw std::logic_error("Cannot normalize zero vector");
        return *this * (1.0 / len);
    }

    Vector3D Vector3D::operator+(const Vector3D& other) const {
        return {_x + other._x, _y + other._y, _z + other._z};
    }

    Vector3D Vector3D::operator-(const Vector3D& other) const {
        return {_x - other._x, _y - other._y, _z - other._z};
    }

    Vector3D Vector3D::operator*(double scalar) const {
        return {_x * scalar, _y * scalar, _z * scalar};
    }


