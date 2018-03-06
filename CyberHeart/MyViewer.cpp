#include "MyViewer.h"

MyViewer::MyViewer(QWidget *parent) : QGLViewer(parent) {};

Point_3 normal(Point_3 point1, Point_3 point2, Point_3 point3) {
    Point_3 vec1 = Point_3(point1.x() - point2.x(), point1.y() - point2.y(), point1.z() - point2.z());
    Point_3 vec2 = Point_3(point3.x() - point2.x(), point3.y() - point2.y(), point3.z() - point2.z());
    Point_3 norm = Point_3(vec1.y()*vec2.z() - vec2.y()*vec1.z(), vec2.x()*vec1.z() - vec1.x()*vec2.z(), vec1.x()*vec2.y() - vec2.x()*vec1.y());
    float normalize = sqrt(norm.x()*norm.x() + norm.y()*norm.y() + norm.z()*norm.z());
    norm = Point_3(-norm.x() / normalize, -norm.y() / normalize, -norm.z() / normalize);

    return norm;
}

bool check_tetrahedron(Tetrahedron tetrahedron, int threshold) {
    if (tetrahedron.point1.x() > threshold && tetrahedron.point2.x() > threshold &&
        tetrahedron.point3.x() > threshold && tetrahedron.point4.x() > threshold)
        return true;
    return false;
}

void MyViewer::draw() {
    if (drawCoordinates) {
        glPointSize(2.0f);
        glBegin(GL_LINES);

        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(100, 0, 0);

        glColor3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 100, 0);

        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 100);

        glEnd();
    }


    if (drawTetrahedra) {
        Point_3 norm;
        glPointSize(2.0f);
        glColor3f(1.0, 0.24, 0.0);
        glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.24, 0.0);
        for (int i = 0; i < tetrahedra.size(); i++) {
            if (check_tetrahedron(tetrahedra[i], 0)) {
                norm = normal(tetrahedra[i].point1, tetrahedra[i].point2, tetrahedra[i].point3);
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point1.x(), tetrahedra[i].point1.y(), tetrahedra[i].point1.z());
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point2.x(), tetrahedra[i].point2.y(), tetrahedra[i].point2.z());
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point3.x(), tetrahedra[i].point3.y(), tetrahedra[i].point3.z());


                norm = normal(tetrahedra[i].point1, tetrahedra[i].point2, tetrahedra[i].point3);
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point1.x(), tetrahedra[i].point1.y(), tetrahedra[i].point1.z());
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point2.x(), tetrahedra[i].point2.y(), tetrahedra[i].point2.z());
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point4.x(), tetrahedra[i].point4.y(), tetrahedra[i].point4.z());


                norm = normal(tetrahedra[i].point1, tetrahedra[i].point2, tetrahedra[i].point3);
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point1.x(), tetrahedra[i].point1.y(), tetrahedra[i].point1.z());
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point3.x(), tetrahedra[i].point3.y(), tetrahedra[i].point3.z());
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point4.x(), tetrahedra[i].point4.y(), tetrahedra[i].point4.z());


                norm = normal(tetrahedra[i].point1, tetrahedra[i].point2, tetrahedra[i].point3);
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point2.x(), tetrahedra[i].point2.y(), tetrahedra[i].point2.z());
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point3.x(), tetrahedra[i].point3.y(), tetrahedra[i].point3.z());
                glNormal3f(norm.x(), norm.y(), norm.z());
                glVertex3f(tetrahedra[i].point4.x(), tetrahedra[i].point4.y(), tetrahedra[i].point4.z());
            }
        }
        glEnd();
    }

    if (drawTriangles) {
        glPointSize(2.0f);
        glColor3f(1.0, 0.24, 0.0);
        glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.24, 0.0);
        for (int i = 0; i < triangles.size(); i++) {
            glNormal3f(triangles[i].normal.x(), triangles[i].normal.y(), triangles[i].normal.z());
            glVertex3f(triangles[i].point1.x(), triangles[i].point1.y(), triangles[i].point1.z());
            glNormal3f(triangles[i].normal.x(), triangles[i].normal.y(), triangles[i].normal.z());
            glVertex3f(triangles[i].point2.x(), triangles[i].point2.y(), triangles[i].point2.z());
            glNormal3f(triangles[i].normal.x(), triangles[i].normal.y(), triangles[i].normal.z());
            glVertex3f(triangles[i].point3.x(), triangles[i].point3.y(), triangles[i].point3.z());
        }
        glEnd();
    }
    
}

void MyViewer::init() {
    restoreStateFromFile();
}