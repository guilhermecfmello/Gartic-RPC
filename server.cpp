#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "line_obj.h"
#include "board_obj.h"
#include "rpc/server.h"

using namespace std;

// vector <string> colors = {"black", "red", "green", "yellow", "blue"};

// vector<Line
int Board_id = 0;
int numberUsers = 0;
int numberRPCs = 0;
// list<Line> lineList;
list<board_obj> boardList;

// board_obj search_board(int id){
//     for (list<board_obj>::iterator it=boardList.begin(); it != boardList.end(); ++it){
//         if(it->getId() == id)
//             // return &it;
//     }
// }

// retorna Boards disponiveis
int getBoards(){

    return Board_id;
}

// string getColor(){
//     string color = colors.pop_back();
//     return color;
// }


// Users connect to a board
void wbadmin(){
    ofstream outfile;
    outfile.open("wbadmin.txt");
    outfile << "===================== Relario wbadmin =====================" << endl;
    outfile << "Numero de quadros: " << Board_id << endl;
    int totalLines = 0;
    for (list<board_obj>::iterator it=boardList.begin(); it != boardList.end(); ++it){
        outfile << "Quadro Id: " << it->getId() << endl;
        outfile << "    Numero de linhas: " << it->getLines().size() << endl;
        totalLines += it->getLines().size();
    }
    outfile << "Total de linhas do servidor: " << totalLines;
}

int addBoard(){
    board_obj b(Board_id++);
    boardList.push_front(b);
    cout << "Board created with id: " << b.getId()  << endl;
    return b.getId();
}

void addLine(int boardId, int x1, int y1, int x2, int y2, string color){

    printf("addLine\n");
    // cout << "BoardID recebido: " << boardId << endl;
    Line line = Line();
    line.set_first_anchor(x1,y1);
    line.set_second_anchor(x2,y2);
    line.set_color(color);

    for (list<board_obj>::iterator it=boardList.begin(); it != boardList.end(); ++it){
        // cout << it->getId() << " == ";
        cout << boardId << endl;
        if(it->getId() == boardId){
            it->addLine(line);
            // cout << "Linha inserida com sucess" << endl;
            // line.console_print_line();
        }   
            
    }

        
}

int getNumberOfLines(int boardId){
    for (list<board_obj>::iterator it=boardList.begin(); it != boardList.end(); ++it){
        if(it->getId() == boardId){
            return it->getLines().size();
        }   
            
    }
}


string getColorBoard(int boardId){
    for (list<board_obj>::iterator it=boardList.begin(); it != boardList.end(); ++it){
        
        if(it->getId() == boardId){
            cout << it->getColor();
            return it->getColor();
        }   
            
    }
}

pixel_data getLines(int boardId){
    pixel_data data;
    list<Line> l;
    // list<board_obj> boardList;
    for (list<board_obj>::iterator it=boardList.begin(); it != boardList.end(); ++it){    
        if (it->getId() == boardId){
            l = it->getLines();
        }
    }

    for (list<Line>::iterator it=l.begin(); it != l.end(); ++it){
        data.push_back({it->getX1(), it->getY1(), it->getX2(), it->getY2(), it->get_color()});
    }
    // count << "Return a list of size: " << data.size() << endl;
    // printf("Return a list of size: %d\n", data.size());
    return data;
}


int main(int argc, char *argv[]) {
    cout << "Starting server on port 8080" << endl;
    // Creating a server that listens on port 8080
    rpc::server srv(8080);


    srv.bind("addLine", &addLine);
    srv.bind("getLines", &getLines);
    srv.bind("getBoards", &getBoards);
    srv.bind("addBoard", &addBoard);
    srv.bind("getColorBoard", &getColorBoard);
    srv.bind("getNumberOfLines", &getNumberOfLines);
    srv.bind("wbadmin", &wbadmin);
    // srv.bind("getColor", &getColor);

    // Run the server loop.
    srv.run();

    return 0;
}



// void addLine(){

// }