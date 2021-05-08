#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include <iostream>
#include "mainwindow.h"

namespace Ui {
class connection;
}

class connection : public QDialog
{
    Q_OBJECT

public:
    explicit connection(QWidget *parent = nullptr);
//    connection(QWidget *parent);
    ~connection();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::connection *ui;
//    MainWindow w;
//    QApplication *a;
};

#endif // CONNECTION_H
