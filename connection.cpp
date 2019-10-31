#include "connection.h"
#include "ui_connection.h"

#include <QString>
#include <string>
#include "mainwindow.h"


using namespace std;

connection::connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connection)
{
    ui->setupUi(this);
    ui->textIp->setText("localhost");
    ui->textName->setText("Fulano");
    ui->textPort->setText("8080");
//    this->a = a2;
}

connection::~connection()
{
    delete ui;
}

void connection::on_buttonBox_accepted()
{

    QString ip = ui->textIp->toPlainText();
    QString name = ui->textName->toPlainText();
    int port = ui->textPort->toPlainText().toInt();

    cout << "accepted with: " << ip.toLocal8Bit().data() << "," << port << ", " << name.toLocal8Bit().data() << endl;

    MainWindow *w = new MainWindow(nullptr, ip, name, port);
    w->show();

//    cout << "End of connection" << endl;

}
