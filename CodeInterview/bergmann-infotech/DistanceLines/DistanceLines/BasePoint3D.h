#pragma once

#ifndef BASEPOINT3D_H
#define BASEPOINT3D_H


/**
 * \brief Abstract base class for 3D objects
 */
class BasePoint3D {
protected:
    double _x, _y, _z;

public:
    BasePoint3D(double x = 0.0, double y = 0.0, double z = 0.0);
    virtual ~BasePoint3D() = default;
    virtual double x() const;
    virtual double y() const;
    virtual double z() const;
};

#endif // BASEPOINT3D_H
