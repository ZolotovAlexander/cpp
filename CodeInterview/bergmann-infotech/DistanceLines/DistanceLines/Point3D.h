#pragma once

#ifndef POINT3D_H
#define POINT3D_H
#include "BasePoint3D.h"

/**
 * \brief Point in 3 decart dimensions
 */
class Point3D : public BasePoint3D {

public:
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0);

    Point3D operator+(const class Vector3D& other_vec) const;

    Vector3D operator-(const Point3D& other) const;
};
#endif
