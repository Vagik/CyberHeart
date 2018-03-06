#include "CyberHeart.h"
#include "ParseSTL.h"
#include <qmessagebox.h>
#include <set>
CyberHeart::CyberHeart(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.parseSTL, SIGNAL(clicked()), this, SLOT(parseSTL()));
    connect(ui.constructTetrahedra, SIGNAL(clicked()), this, SLOT(constructTetrahedra()));
    connect(ui.drawTriangles, SIGNAL(clicked()), this, SLOT(drawTriangles()));
    connect(ui.drawTetrahedra, SIGNAL(clicked()), this, SLOT(drawTetrahedra()));
    connect(ui.drawCoordinates, SIGNAL(clicked()), this, SLOT(drawCoordinates()));
}


void CyberHeart::parseSTL() {
    ui.widget->triangles.clear();
    ui.widget->tetrahedra.clear();
    Point_3 point1, point2, point3, normal;
    int size = 0;
    string *files = new string[11];
    vector<int> selected;
    initFiles(files);

    if (ui.Part_1->isChecked())
        selected.push_back(0);
    if (ui.Part_2->isChecked())
        selected.push_back(1);
    if (ui.Part_3->isChecked())
        selected.push_back(2);
    if (ui.Part_4->isChecked())
        selected.push_back(3);
    if (ui.Part_5->isChecked())
        selected.push_back(4);
    if (ui.Part_6->isChecked())
        selected.push_back(5);
    if (ui.Part_7->isChecked())
        selected.push_back(6);
    if (ui.Part_8->isChecked())
        selected.push_back(7);
    if (ui.Part_9->isChecked())
        selected.push_back(8);
    if (ui.Part_10->isChecked())
        selected.push_back(9);
    if (ui.Part_11->isChecked())
        selected.push_back(10);


    for (int i = 0; i < selected.size(); i++) {
        ifstream file(files[selected[i]]);
        string line;
        bool norm = true;
        int point_counter = 0;
        while (getline(file, line)) {
            if (norm) {
                normal = find_normal(line);
                if (normal.x() != 1000) {                         // Если норма найдена, то прекращаем её поиски, пока не найдём три точки
                    norm = false;
                }
            }
            else
                if (point_counter == 0) {
                    point1 = find_vertex(line);
                    if (point1.x() != 1000) {                         // Если нашли первую точку, то переходим к поиску второй точки
                        point_counter++;
                    }
                }
                else
                    if (point_counter == 1) {
                        point2 = find_vertex(line);
                        if (point2.x() != 1000) {                         // Если нашли вторую точку, то переходим к поиску третьей точки
                            point_counter++;
                        }
                    }
                    else
                        if (point_counter == 2) {
                            point3 = find_vertex(line);
                            if (point3.x() != 1000) {                         // Если нашли третью точку, то добавляем треугольник в вектор
                                point_counter = 0;
                                norm = true;
                                    ui.widget->triangles.push_back(Triangle(point1, point2, point3, normal));
                            }
                        }
        }
    }
    QString tmp = "Number of triangles: " + QString::number(ui.widget->triangles.size());
    QMessageBox::information(this, "ParseSTL", tmp);
}


Point_3 find_center(Triangle triangle) {
    float x = (triangle.point1.x() + triangle.point3.x() + triangle.point2.x()) / 3;
    float y = (triangle.point1.y() + triangle.point3.y() + triangle.point2.y()) / 3;
    float z = (triangle.point1.z() + triangle.point3.z() + triangle.point2.z()) / 3;

    return Point_3(x, y, z);
}


void CyberHeart::constructTetrahedra() {
    Triangles in_triangles;
    for (int i = 0; i < ui.widget->triangles.size(); i++) {
        in_triangles.push_back(Triangle(Point_3(0.9 * ui.widget->triangles[i].point1.x(), 0.9 * ui.widget->triangles[i].point1.y(), 0.9 * ui.widget->triangles[i].point1.z()),
            Point_3(0.9 * ui.widget->triangles[i].point2.x(), 0.9 * ui.widget->triangles[i].point2.y(), 0.9 * ui.widget->triangles[i].point2.z()),
            Point_3(0.9 * ui.widget->triangles[i].point3.x(), 0.9 * ui.widget->triangles[i].point3.y(), 0.9 * ui.widget->triangles[i].point3.z()),
            Point_3(ui.widget->triangles[i].normal.x(), ui.widget->triangles[i].point1.y(), ui.widget->triangles[i].point1.z())));
    }

    for (int i = 0; i < in_triangles.size(); i++) {
        Point_3 center = find_center(in_triangles[i]);
        ui.widget->tetrahedra.push_back(Tetrahedron(center, ui.widget->triangles[i].point1, ui.widget->triangles[i].point2, ui.widget->triangles[i].point3));
    }

    in_triangles.clear();
}
void CyberHeart::drawTetrahedra() {
    ui.widget->drawTetrahedra = !ui.widget->drawTetrahedra;
}

void CyberHeart::drawTriangles() {
    ui.widget->drawTriangles = !ui.widget->drawTriangles;
}

void CyberHeart::drawCoordinates() {
    ui.widget->drawCoordinates = !ui.widget->drawCoordinates;
}