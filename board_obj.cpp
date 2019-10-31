#include "board_obj.h"


board_obj::board_obj(int id)
{
    this->id = id;
    this->lineList = list<Line>();
    this->colors = {"black", "blue", "red", "magenta", "green", "yellow", "DarkBlue"} ;
}

list<Line> board_obj::getLines(){
    return this->lineList;
}

void board_obj::addLine(Line l){
    this->lineList.push_back(l);
}

int board_obj::getId(){
    return this->id;
}

string board_obj::getColor(){
	string c;
	if(this->colors.size() > 0){
		c = this->colors.back();
		this->colors.pop_back();	
	}
	else
		c = "black";
	return c;
}