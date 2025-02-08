#include "DistanceLines.h"

/**
 * \Find closest distance between point and line segment 
 * \param point 
 * \param segment 
 * \return 
 */
double distance_from_point_to_segment(const Point3D& point, const Segment3D& segment) {
    Vector3D seg_dir = segment.direction();
    double seg_length_sq = seg_dir.dot(seg_dir);
    if (seg_length_sq == 0.0) { // Dot
        return (point - segment.start()).length();
    }

    Vector3D vec_to_point = point - segment.start();
    double t = vec_to_point.dot(seg_dir) / seg_length_sq;
    t = std::clamp(t, 0.0, 1.0);
    Point3D closest = segment.start() + seg_dir * t;
    return (point - closest).length();
}

/**
 * \Find closest dots on two line segments
 * \param seg1 
 * \param seg2 
 * \return 
 */
std::pair<double, double> closest_dots(const Segment3D& seg1, const Segment3D& seg2) {
    Vector3D u = seg1.direction();
    Vector3D v = seg2.direction();
    Vector3D w = seg1.start() - seg2.start();
    double a = u.dot(u);
    double b = u.dot(v);
    double c = v.dot(v);
    double d = u.dot(w);
    double e = v.dot(w);
    double denom = a * c - b * b;

    double s, t;
    if (denom < 1e-9) { // Paralell lines
        s = 0.0;
        t = (b > c) ? d / b : e / c;
    }
    else {
        s = (b * e - c * d) / denom;
        t = (a * e - b * d) / denom;
    }
    return { s, t };
}

/**
 * \Calculate distance between two lines 
 * \param segment1 
 * \param segment2 
 * \return double as distance between two lines
 */
double distance_between_lines(const Segment3D& segment1, const Segment3D& segment2) {
    auto [s, t] = closest_dots(segment1, segment2);
    s = std::clamp(s, 0.0, 1.0);
    t = std::clamp(t, 0.0, 1.0);

    Point3D p = segment1.start() + segment1.direction() * s;
    Point3D q = segment2.start() + segment2.direction() * t;
    double min_dist = (p - q).length();

    double d1 = distance_from_point_to_segment(segment1.start(), segment2);
    double d2 = distance_from_point_to_segment(segment1.end(), segment2);
    double d3 = distance_from_point_to_segment(segment2.start(), segment1);
    double d4 = distance_from_point_to_segment(segment2.end(), segment1);

    return std::min({ min_dist, d1, d2, d3, d4 });
}


