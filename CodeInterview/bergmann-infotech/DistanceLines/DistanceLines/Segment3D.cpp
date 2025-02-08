#include "DistanceLines.h"

Segment3D::Segment3D(const Point3D& start, const Point3D& end) : _start(start), _end(end)
{
}

const Point3D& Segment3D::start() const { return _start; }
const Point3D& Segment3D::end() const { return _end; }

Vector3D Segment3D::direction() const
{
	return _end - _start;
}

double Segment3D::length() const
{
	return direction().length();
}
