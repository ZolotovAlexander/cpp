#pragma once
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <string>

#include "Point3D.h"
#include "Segment3D.h"
#include "Vector3D.h"


double distance_from_point_to_segment(const Point3D& point, const Segment3D& segment);
std::pair<double, double> closest_dots(const Segment3D& seg1, const Segment3D& seg2);
double distance_between_lines(const Segment3D& segment1, const Segment3D& segment2);