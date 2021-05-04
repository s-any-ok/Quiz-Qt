#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gamewindow.h"
#include "gamecontroller.h"
#include "question.h"
#include "gameinitializer.h"
#include "gamecontroller.h"
#include "databasemanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
