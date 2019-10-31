#include "mainwindow.h"

#include <iostream>
#include <QApplication>
#include "connection.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection c;

    c.show();

//    MainWindow w;
//    w.show();
    return a.exec();
}
