#include <string>
#include <fstream>
#include <iostream>
#include "typedefs.h"

using namespace std;

string copyWord(string str, int from, int *fin_pos) {
    string ret = "";
    int i = from;
    while (str[i] != ' ' && str[i] != '\n') {
        ret += str[i];
        i++;
    }
    *fin_pos = i;
    return ret;
}

Point_3 find_normal(string line) {
    line += '\n';
    size_t pos = line.find("facet normal");
    if (pos != string::npos) {
        int fin_pos = 0;
        float point_x = atof(copyWord(line, pos + 13, &fin_pos).c_str());
        float point_y = atof(copyWord(line, fin_pos + 1, &fin_pos).c_str());
        float point_z = atof(copyWord(line, fin_pos + 1, &fin_pos).c_str());
        return Point_3(point_x, point_y, point_z);
    }
    else
        return Point_3(1000, 0, 0);
}

Point_3 find_vertex(string line) {
    line += '\n';
    size_t pos = line.find("vertex");
    if (pos != string::npos) {
        int fin_pos = 0;
        float point_x = atof(copyWord(line, pos + 8, &fin_pos).c_str());
        float point_y = atof(copyWord(line, fin_pos + 1, &fin_pos).c_str());
        float point_z = atof(copyWord(line, fin_pos + 1, &fin_pos).c_str());
        return Point_3(point_x, point_y, point_z);
    }
    else
        return Point_3(1000,0,0);
}

void initFiles(string *files) {
    files[0] = "./Поверхности сердца/00_heart_shell.stl";
    files[1] = "./Поверхности сердца/01_left_atrium.stl";
    files[2] = "./Поверхности сердца/02_left_ventricle.stl";
    files[3] = "./Поверхности сердца/03_right_atrium.stl";
    files[4] = "./Поверхности сердца/04_right_ventricle.stl";
    files[5] = "./Поверхности сердца/05_fibrous2.stl";
    files[6] = "./Поверхности сердца/06_AV_node.stl";
    files[7] = "./Поверхности сердца/07_SA_node.stl";
    files[8] = "./Поверхности сердца/08_His_bundle.stl";
    files[9] = "./Поверхности сердца/09_Bachmann_bundle.stl";
    files[10] = "./Поверхности сердца/10_Sin_AV_2.stl";
}