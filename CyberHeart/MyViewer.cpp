#include "MyViewer.h"

MyViewer::MyViewer(QWidget *parent) : QGLViewer(parent) {};


void MyViewer::draw() {
    if (drawHeart) {

        glPointSize(2.0f);
        glColor3f(1.0, 0.14, 0.0);
        glBegin(GL_TRIANGLES);
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