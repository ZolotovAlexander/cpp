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

   /**
	* \brief Dot product of this vector with another
	* \param other
	* \return
	*/
    double dot(const Vector3D& other) const;

    /**
     * \brief Cross product of this vector with another
     * \param other 
     * \return 
     */
    Vector3D cross(const Vector3D& other) const;

    /**
     * \brief Length of the vector
     * \return 
     */
    double length() const;

    /**
     * \brief Normalized (unit-length) vector
     * \return 
     */
    Vector3D normalize() const;

    Vector3D operator+(const Vector3D& other) const;

    Vector3D operator-(const Vector3D& other) const;

    Vector3D operator*(double scalar) const;
};

#endif