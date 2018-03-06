#pragma once
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_3 Point_3;

class Tetrahedron {
public:
    Point_3 point1;
    Point_3 point2;
    Point_3 point3;
    Point_3 point4;
    Tetrahedron(Point_3 _point1, Point_3 _point2, Point_3 _point3, Point_3 _point4) {
        point1 = _point1;
        point2 = _point2;
        point3 = _point3;
        point4 = _point4;
    }
};