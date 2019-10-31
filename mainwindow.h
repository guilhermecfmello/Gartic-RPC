#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "board.h"
#include <rpc/client.h>


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QWidget *parent, QString ip, QString name, int port);
    void inicializa();
    ~MainWindow();

private slots:
    void on_boardCreate_clicked();

    void on_boardSelect_clicked();

private:
    Ui::MainWindow *ui;
    QString ip;
    QString name;
    int port;
    rpc::client *c;
//    Index index;
};
#endif // MAINWINDOW_H
