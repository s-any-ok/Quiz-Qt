#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "clientmanager.h"
#include "mainwindow.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void setLevelData(int levelId);
    int getChosenId();
    void changeCorrectAnswerColor(int answerId, bool isShowen = false);
    void resetRadioButtons();
    void setClient(ClientManager *client);

private slots:
    void on_checkAnswerButton_clicked();

    void on_nextQuestionButton_clicked();

    void on_getGameDataButton_clicked();

private:
    Ui::GameWindow *ui;
    ClientManager* _client;
};

#endif // GAMEWINDOW_H
