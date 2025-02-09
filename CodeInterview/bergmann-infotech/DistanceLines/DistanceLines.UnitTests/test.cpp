#include "pch.h"
#include <gtest/gtest.h>
#include "../DistanceLines/DistanceLines.h"

//1 Basic operations of Point3D
TEST(Point3DTest, BasicOperations) {
    // Check - subtraction of two points resulting in a vector
    Point3D p1(1.0, 2.0, 3.0);
    Point3D p2(4.0, 5.0, 6.0);

    Vector3D v = p2 - p1; // difference in coordinates results - valid Vector3D
    EXPECT_DOUBLE_EQ(v.x(), 3.0);
    EXPECT_DOUBLE_EQ(v.y(), 3.0);
    EXPECT_DOUBLE_EQ(v.z(), 3.0);

    Vector3D v2 = p1 - p2; 
    EXPECT_DOUBLE_EQ(v2.x(), -3.0);
    EXPECT_DOUBLE_EQ(v2.y(), -3.0);
    EXPECT_DOUBLE_EQ(v2.z(), -3.0);

    Vector3D res = v2 - v;

    EXPECT_DOUBLE_EQ(res.x(), -6.0);
    EXPECT_DOUBLE_EQ(res.y(), -6.0);
    EXPECT_DOUBLE_EQ(res.z(), -6.0);

    Vector3D res2 = v2 + v; //dot

    EXPECT_DOUBLE_EQ(res2.x(), 0.0);
    EXPECT_DOUBLE_EQ(res2.y(), 0.0);
    EXPECT_DOUBLE_EQ(res2.z(), 0.0);
}

//2 Dot product calculation of two perpendicular vectors
TEST(Vector3DTest, DotProduct) {
    // Checks - dot product of two perpendicular vectors is zero
    Vector3D v1(1, 0, 0);
    Vector3D v2(0, 1, 0);

    EXPECT_DOUBLE_EQ(v1.dot(v2), 0.0);
}

//3 Cross product calculation of two perpendicular vectors
TEST(Vector3DTest, CrossProduct) {
    // Cross product of (1,0,0) and (0,1,0) results in (0,0,1)
    Vector3D v1(1, 0, 0);
    Vector3D v2(0, 1, 0);

    Vector3D v3 = v1.cross(v2);

    EXPECT_DOUBLE_EQ(v3.x(), 0.0);
    EXPECT_DOUBLE_EQ(v3.y(), 0.0);
    EXPECT_DOUBLE_EQ(v3.z(), 1.0);
}

//4 Segment3D correctly calculates its direction vector
TEST(Segment3DTest, DirectionCalculation) {
    // Direction vector correctly represents difference between segment endpoints
    Point3D p1(0, 0, 0);
    Point3D p2(1, 1, 1);
    Segment3D segment(p1, p2);

    Vector3D dir = segment.direction();

    EXPECT_DOUBLE_EQ(dir.x(), 1.0);
    EXPECT_DOUBLE_EQ(dir.y(), 1.0);
    EXPECT_DOUBLE_EQ(dir.z(), 1.0);
}

//5 Distance calculation from a point to a segment
TEST(DistanceLinesTest, DistanceFromPointToSegment) {
    // Ensures that the computed distance is correct for a point not on segment
    Point3D p(1, 1, 1);
    Segment3D segment(Point3D(0, 0, 0), Point3D(2, 0, 0));

    double dist = distance_from_point_to_segment(p, segment);
    EXPECT_NEAR(dist, std::sqrt(2.0), 1e-6);
}

//6 Closest dots on two segments
TEST(DistanceLinesTest, ClosestDots) {
    // Closest dots between two parallel line segments
    Segment3D seg1(Point3D(0, 0, 0), Point3D(1, 0, 0));
    Segment3D seg2(Point3D(0, 1, 0), Point3D(1, 1, 0));

    auto [s,t] = closest_dots(seg1, seg2);
    EXPECT_NEAR(s, 0.0, 1e-6);
    EXPECT_NEAR(t, 0.0, 1e-6);
}

//7 Distance between two parallel line segments
TEST(DistanceLinesTest, DistanceBetweenLines) {
    // Minimal perpendicular distance between parallel segments
    Segment3D seg1(Point3D(0, 0, 0), Point3D(1, 0, 0));
    Segment3D seg2(Point3D(0, 1, 0), Point3D(1, 1, 0));

    double dist = distance_between_lines(seg1, seg2);
    EXPECT_NEAR(dist, 1.0, 1e-6);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
