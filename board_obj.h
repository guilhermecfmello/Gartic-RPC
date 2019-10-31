#ifndef BOARD_OBJ_H
#define BOARD_OBJ_H

#include <list>
#include <iostream>
#include <vector>
#include <string>

#include "line_obj.h"

using namespace std;

class board_obj
{
public:
    board_obj(int id);
    void addLine(Line);
    list<Line> getLines();
    int getId();
    string getColor();

private:
    int id;
    list<Line> lineList;
    vector<string> colors;

};

#endif // BOARD_OBJ_H
