#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>

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

private slots:
    void on_checkAnswerButton_clicked();

    void on_nextQuestionButton_clicked();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
