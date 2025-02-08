#pragma once

#ifndef SEGMENT3D_H
#define SEGMENT3D_H
#include "Vector3D.h"

class Segment3D {
private:
    Point3D _start, _end;

public:
    Segment3D(const Point3D& start, const Point3D& end);

    const Point3D& start() const;
    const Point3D& end() const;

    Vector3D direction() const;

    double length() const;
};

#endif
