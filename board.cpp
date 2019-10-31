#include "board.h"
#include "ui_board.h"

#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <rpc/client.h>
#include <QMouseEvent>
#include <list>
#include <rpc/client.h>

#include <QThread>
#include <QFuture>
#include <QtDebug>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFutureWatcher>

int Board::add (int a, int b){
    return a + b;
}


Board::Board(QWidget *parent,
            rpc::client *c2,
             QString ip,
             int port,
             int boardId,
             string color) :
    QDialog(parent),
    ui(new Ui::Board)
{



    ui->setupUi(this);

    this->color = color;
    this->ip = ip;
    this->port = port;

    image = QPixmap(721,531);
    image.fill();
    ui->white_board->setPixmap(image);



    this->c = c2;
//    std::thread t1 (&Board::refreshBoard, this);
//    t1.join();
    this->boardId = boardId;
//    cout << "Before thread" << endl;
    QFuture<void> t1 = QtConcurrent::run(this, &Board::refreshBoard);
    cout << "After thread" << endl;
//    QApplication::exec();
}

Board::~Board()
{
    delete ui;
}


void Board::mousePressEvent(QMouseEvent* ev )
{
    const QPoint p = ev->pos();

    if(!line.get_first_anchor_setted())
        line.set_first_anchor(p.x(), p.y());
    else
        line.set_second_anchor(p.x(),p.y());


    if(line.get_ready()){
        QPainter painter(&image);

        QPen pointpen(QColor(this->color.c_str()));
        pointpen.setWidth(4);

        painter.setPen(pointpen);
        painter.drawLine(line.getX1(),line.getY1(), line.getX2(), line.getY2());
        ui->white_board->setPixmap(image);

        cout << "Drawing on: " << this->boardId << endl;
        this->c->call("addLine",this->boardId, line.getX1(),line.getY1(),line.getX2(),line.getY2(), this->color);

        this->line = Line();
    }
}

void Board::paintEvent(QPaintEvent *e){
}


void Board::refreshBoard(){
//    cout << "Refresh start" << endl;
    int lastSize = this->c->call("getNumberOfLines", this->boardId).as<int>() - 1;

    while(true){

        int size = this->c->call("getNumberOfLines", this->boardId).as<int>();

        if(lastSize != size){
            auto result_obj = this->c->async_call("getLines", this->boardId);
            auto result = result_obj.get().as<pixel_data>();
            string color;
            for (unsigned long int i = 0; i < result.size(); i++) {
                color = result[i].color;
                QPainter painter(&image);

                QPen pointpen(QColor(color.c_str()));
                pointpen.setWidth(4);

                painter.setPen(pointpen);
                painter.drawLine(result[i].x1,result[i].y1, result[i].x2, result[i].y2);
                ui->white_board->setPixmap(image);

            }
            lastSize = size;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
         }
    }

}

void Board::on_pushButton_clicked()
{
    this->close();
}
