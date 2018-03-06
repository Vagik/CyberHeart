#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CyberHeart.h"
#include "MyViewer.h"

class CyberHeart : public QMainWindow
{
    Q_OBJECT

public:
    CyberHeart(QWidget *parent = Q_NULLPTR);
public slots:
    void drawTriangles();
    void drawTetrahedra();

    void parseSTL();
    void constructTetrahedra();

    void drawCoordinates();
private:
    Ui::CyberHeartClass ui;
};
