#pragma once
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_3 Point_3;

class Triangle {
public:
    Point_3 point1;
    Point_3 point2;
    Point_3 point3;
    Point_3 normal;
    Triangle(Point_3 _point1, Point_3 _point2, Point_3 _point3, Point_3 _normal) {
        point1 = _point1;
        point2 = _point2;
        point3 = _point3;
        normal = _normal;
    }
};