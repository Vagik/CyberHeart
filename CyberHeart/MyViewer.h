#pragma once
#include <typedefs.h>
#include <QGLViewer\qglviewer.h>

class MyViewer : public QGLViewer {
public:
    MyViewer(QWidget *parent);
    Points3 points;
    Triangles triangles;
    bool drawHeart = false;

protected:
    virtual void draw();
    virtual void init();

};