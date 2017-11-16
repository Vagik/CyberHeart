#include "CyberHeart.h"
#include "ParseSTL.h"
#include <qmessagebox.h>
CyberHeart::CyberHeart(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.ParseSTL, SIGNAL(clicked()), this, SLOT(ParseSTL()));
    connect(ui.drawHeart, SIGNAL(clicked()), this, SLOT(drawHeart()));
}

void CyberHeart::ParseSTL() {
    Point_3 point1, point2, point3, normal;
    int size = 0;
    string *files = new string[11];
    initFiles(files);
    for (int i = 0; i < 11; i++) {
        ifstream file(files[i]);
        string line;
        bool norm = true;
        int point_counter = 0;
        while (getline(file, line))
        {
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
void CyberHeart::drawHeart() {
    ui.widget->drawHeart = !ui.widget->drawHeart;
}