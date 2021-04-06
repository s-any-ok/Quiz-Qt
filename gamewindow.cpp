#include <QDebug>
#include <QTextCodec>
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gamecontroller.h"
#include "question.h"
#include "gameinitializer.h"

GameInitializer gameInitializer;
GameController game(gameInitializer);
int a = 0;
GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->resultBox->hide();
    QString amountOfQuestions = game.getAmountOfQuestions();
    ui->amountOfQuestions->setText(amountOfQuestions);
    setLevelData(game.getLevel());
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setLevelData(int levelId) {
    QString startQuestion = game.getCurrentQuestion(levelId);
    QString firstAnswer = game.getCurrentAnswer(levelId, 0);
    QString secondAnswer = game.getCurrentAnswer(levelId, 1);
    QString thirdAnswer = game.getCurrentAnswer(levelId, 2);
    QString fourthAnswer = game.getCurrentAnswer(levelId, 3);
    QString currentQuestionNumber = QString::number(levelId + 1);
    QString points = QString::number(game.getPoints());

    ui->pointsValue->setText(points);
    ui->currentQuestionNumber->setText(currentQuestionNumber);
    ui->currectQuestion->setText(startQuestion);
    ui->radioButton_1->setText(firstAnswer);
    ui->radioButton_2->setText(secondAnswer);
    ui->radioButton_3->setText(thirdAnswer);
    ui->radioButton_4->setText(fourthAnswer);
}
int GameWindow::getChosenId()
{
    int btnId = 0;
    btnId = ui->radioButtonsGroup->checkedId();
    btnId *= (-1);
    btnId -= 1;
    return btnId;
}
void GameWindow::changeCorrectAnswerColor(int answerId, bool isShowen){
    string color = "green";
    if (isShowen) color = "black";
    QString qcolor = QString::fromStdString(color);
    switch (answerId) {
            case 1:
                ui->radioButton_1->setStyleSheet("QRadioButton { color : " + qcolor + "; }");
            break;
            case 2:
                ui->radioButton_2->setStyleSheet("QRadioButton { color : " + qcolor + "; }");
            break;
            case 3:
                ui->radioButton_3->setStyleSheet("QRadioButton { color : " + qcolor + "; }");
            break;
            case 4:
                ui->radioButton_4->setStyleSheet("QRadioButton { color : " + qcolor + "; }");
            break;
        }
}
void GameWindow::resetRadioButtons(){
    if (getChosenId() != 0) {
        ui->radioButtonsGroup->setExclusive(false);
        ui->radioButtonsGroup->checkedButton()->setChecked(false);
        ui->radioButtonsGroup->setExclusive(true);
    }
    changeCorrectAnswerColor(game.getCorrectAnswerId(game.getLevel()), true);
}

void GameWindow::on_checkAnswerButton_clicked()
{
    int btnId = getChosenId();
    int currentLevel = game.getLevel();
    bool isCorrect = game.isCorrectAnswer(currentLevel, btnId);
    if (isCorrect) {
        int curentPoints = game.getPoints();
        curentPoints++;
        game.setPoints(curentPoints);
    }
    changeCorrectAnswerColor(game.getCorrectAnswerId(currentLevel));
    ui->checkAnswerButton->hide();
    ui->nextQuestionButton->show();
}

void GameWindow::on_nextQuestionButton_clicked()
{
    resetRadioButtons();
    game.incLevel();
    int currentLevel = game.getLevel();
    int amountOfQuestions = game.getAmountOfQuestions().toInt();
    if (amountOfQuestions <= currentLevel) {
        QString points = QString::number(game.getPoints());
        ui->resultPointsValue->setText(points);
        ui->resultBox->show();
        ui->nextQuestionButton->hide();
        ui->currectQuestion->hide();
        ui->radioButtons->hide();
    } else {
        setLevelData(currentLevel);
        ui->checkAnswerButton->show();
        ui->nextQuestionButton->hide();
    }
}
