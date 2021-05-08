#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "rpc/msgpack.hpp"
#include <vector>
#include <string>

struct lines{
    int x1,y1,x2,y2;
    std::string color;
    MSGPACK_DEFINE_ARRAY(x1,y1,x2,y2, color);
};

using namespace std;

using pixel_data = std::vector<lines>;

class Line
{
public:
    // getters
    int getX1();
    int getY1();
    int getX2();
    int getY2();

    //constructor
    Line();

    // return true if all coordenate's line are setted
    bool get_ready();

    // set the first position of the line
    bool set_first_anchor(int x1, int y1);

    // set the second position of the line
    bool set_second_anchor(int x2, int y2);

    // return true if first_anchor is already setted, however return false
    bool get_first_anchor_setted();

    // print line coordenates on terminal
    void console_print_line();

    void set_color(string color);

    string get_color();

private:
    int x1;
    int y1;
    int x2;
    int y2;
    std::string color;
    bool ready;


};



#endif // LINE_H
