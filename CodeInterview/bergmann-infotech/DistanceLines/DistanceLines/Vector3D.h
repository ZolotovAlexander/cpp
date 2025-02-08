#pragma once

#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
private:
    double _x, _y, _z;

public:
    Vector3D(double x , double y, double z );

    double x() const;
    double y() const;
    double z() const;

    double dot(const Vector3D& other) const;

    Vector3D cross(const Vector3D& other) const;

    double length() const;

    Vector3D normalize() const;

    Vector3D operator+(const Vector3D& other) const;

    Vector3D operator-(const Vector3D& other) const;

    Vector3D operator*(double scalar) const;
};

#endif