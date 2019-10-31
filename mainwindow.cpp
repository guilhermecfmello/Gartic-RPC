#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>


//using namespace std;


MainWindow::MainWindow(QWidget *parent,
                       QString ip,
                       QString name,
                       int port) :
    QMainWindow(parent)
  , ui(new Ui::MainWindow){

    ui->setupUi(this);

    this->ip = ip;
    this->name = name;
    this->port = port;


    this->inicializa();
//    cout << "Mainwindow" << endl;




}

void MainWindow::inicializa(){
    rpc::client c2 (this->ip.toLocal8Bit().data(), port);
    this->c = &c2;
    int n = this->c->call("getBoards").as<int>();
    cout << "N: " << n << endl;
    if(n == 0)
        ui->boardsList->addItem("Ainda nao ha quadros");
    for(int i = 0; i < n ; i++){
        ui->boardsList->addItem(QString::number(i));
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rpc::client c2 (this->ip.toLocal8Bit().data(), this->port);
    this->c = &c2;

    int n = this->c->call("getBoards").as<int>();
    cout << "N: " << n << endl;
    if(n == 0)
        ui->boardsList->addItem("Ainda nao ha quadros");
    for(int i = 0; i < n ; i++){
        ui->boardsList->addItem(QString::number(i));
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_boardCreate_clicked()
{
    rpc::client c2 (this->ip.toLocal8Bit().data(), this->port);
    this->c = &c2;


    int boardId = this->c->call("addBoard").as<int>();
//    cout << "Board " << boardId << " criado com sucesso" << endl;
    string color = this->c->call("getColorBoard", boardId).as<string>();
    cout << "Quadro criado: " << boardId << endl;
    cout << "Sua cor eh: " << color << endl;
    Board board(NULL, this->c, this->ip, this->port, boardId, color);
    board.exec();
    cout << "fim cria" << endl;
    ui->boardsList->clear();
    this->inicializa();
}

void MainWindow::on_boardSelect_clicked()
{
    rpc::client c2 (this->ip.toLocal8Bit().data(), this->port);
    this->c = &c2;


    int boardId = ui->boardsList->currentIndex();
//    Board board(NULL, this->c, boardId);
    string color = this->c->call("getColorBoard", boardId).as<string>();
    Board board(NULL, this->c, this->ip, this->port, boardId, color);
    cout << "Entrou no quadro " << boardId << endl;
    cout << "Sua cor eh " << color << endl;
    board.exec();
    cout << "fim seleciona" << endl;
    ui->boardsList->clear();
    this->inicializa();
}
