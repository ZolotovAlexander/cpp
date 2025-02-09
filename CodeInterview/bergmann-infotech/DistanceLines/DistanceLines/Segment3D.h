#pragma once

#ifndef SEGMENT3D_H
#define SEGMENT3D_H
#include "Vector3D.h"

class Segment3D {
private:
    Point3D _start, _end;

public:
    Segment3D(const Point3D& start, const Point3D& end);

    /**
     * \brief Start line
     * \return 
     */
    const Point3D& start() const;

    /**
     * \brief End line
     * \return 
     */
    const Point3D& end() const;

    /**
     * \brief Line direction
     * \return 
     */
    Vector3D direction() const;

    /**
     * \brief Lenght of line
     * \return 
     */
    double length() const;
};

#endif
