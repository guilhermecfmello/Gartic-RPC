#ifndef BOARD_H
#define BOARD_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <iostream>
#include <QMouseEvent>
#include <rpc/client.h>

#include "line_obj.h"
#include <list>

using namespace std;

namespace Ui {
class Board;
}

class Board : public QDialog
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    void mousePressEvent( QMouseEvent* ev );
    ~Board();
    Board(QWidget *parent = nullptr,
          rpc::client *c2 = NULL,
          QString ip = "localhost",
          int port = 8080,
          int boardId = 0,
          string color = "black");


private:
    Ui::Board *ui;
    QPainter painter;
//    QColor penColor;
    QString ip;
    int port;
    string color;
    int penWidth;
    QPoint lastPoint;
    rpc::client *c;
    QPixmap image;
    Line line = Line();
    int boardId;
//    list<Line> lineList();
    void refreshBoard();
    int add(int a, int b);
//    void run();

protected:
    void paintEvent(QPaintEvent *e);
private slots:

    void on_pushButton_clicked();
};

#endif // BOARD_H
