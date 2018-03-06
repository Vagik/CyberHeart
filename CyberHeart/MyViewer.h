#pragma once
#include <typedefs.h>
#include <QGLViewer\qglviewer.h>

class MyViewer : public QGLViewer {
public:
    MyViewer(QWidget *parent);
    Points3 points;
    Triangles triangles;
    Tetrahedra tetrahedra;
    bool drawTriangles = false, drawTetrahedra = false, drawCoordinates = false;
 

protected:
    virtual void draw();
    virtual void init();

};