#pragma once

#ifndef POINT3D_H
#define POINT3D_H

/**
 * \brief Point in 3 decart dimensions
 */
class Point3D {
private:
    double _x, _y, _z;

public:
    Point3D(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    Point3D operator+(const class Vector3D& other_vec) const;

    Vector3D operator-(const Point3D& other) const;
};
#endif
