#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

class User
{
public:
    User(string name);
    void setBoard();


private:
    string name;
    int board_id;


};

#endif // USER_H
