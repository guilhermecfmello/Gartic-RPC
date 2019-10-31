#include "line_obj.h"

Line::Line()
{
    this->x1 = -1;
    this->y1 = -1;
    this->x2 = -1;
    this->y2 = -1;
    this->ready = false;
}

void Line::console_print_line(){
    std::cout << std::endl << " ================================= printing line ================================= " << std::endl;
    std::cout << "( " << this->x1 << ", " << this->y1 << " )" << std::endl;
    std::cout << "( " << this->x2 << ", " << this->y2 << " )" << std::endl;
}

bool Line::get_ready(){
    return this->ready;
}

int Line::getX1(){
    return this->x1;
}
int Line::getY1(){
    return this->y1;
}

int Line::getX2(){
    return this->x2;
}
int Line::getY2(){
    return this->y2;
}

bool Line::get_first_anchor_setted(){
    if (this->x1 != -1 && this->y1 != -1)
        return true;
    return false;
}

void Line::set_color(std::string color){
    this->color = color;
}

//std::string Line::getColor()

std::string Line::get_color(){
    return this->color;
}

bool Line::set_first_anchor(int x1, int y1){
    this->x1 = x1;
    this->y1 = y1;
    if(this->x2 != -1 && this->y2 != -1)
        this->ready = true;
    return true;
}


bool Line::set_second_anchor(int x2, int y2){
    this->x2 = x2;
    this->y2 = y2;
    if(this->x1 != -1 && this->y1 != -1)
        this->ready = true;
   return true;
}
