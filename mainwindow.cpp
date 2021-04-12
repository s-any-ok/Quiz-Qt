#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gamewindow.h"
#include "gamecontroller.h"
#include "question.h"
#include "gameinitializer.h"
#include "databaseconnection.h"
#include "QSqlQuery"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DatabaseConnection db;
    db.Connect();
//    QSqlQuery query = new QSqlQuery(db.getDB());
    QSqlQuery query(db.getDB());
    query.exec("select answer from dbo.Answers");
//    QSqlQuery query("select answer from dbo.Answers");
    while(query.next())
    {
        QString s = query.value(0).toString();
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    hide();
    GameWindow gameWindow;
    gameWindow.setModal(true);
    gameWindow.exec();
}
