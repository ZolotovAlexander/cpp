#include "DistanceLines.h"

int main() {
    Point3D a(0, 0, 0);
    Point3D b(1, 0, 0);
    Segment3D seg1(a, b);

    Point3D c(0, 1, 0);
    Point3D d(0, 1, 1);
    Segment3D seg2(c, d);

    double dist = distance_between_lines(seg1, seg2); //return  1.0

    printf("distance = %f", dist);
    return 0;
}
