#include <QDebug>
#include <QTextCodec>
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gamecontroller.h"
#include "question.h"
#include "gameinitializer.h"
#include "gamedatawriter.h"
#include "gamemanager.h"
#include "datamanager.h"
#include <chrono>
#include <thread>

GameInitializer gameInitializer;
GameDataWriter gameDataWriter;
GameManager gameManager(gameInitializer, gameDataWriter);
GameController gameController(gameManager);

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->resultBox->hide();
    ClientManager *client = new ClientManager();
    setClient(client);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setClient(ClientManager *client)
{
    _client = client;
    _client->getDataFromServer();
}

void GameWindow::on_getGameDataButton_clicked()
{
    ui->getGameDataButton->hide();
    auto data = _client->getJsonData();
    gameController.initQuestionFromServer(data);
    QString amountOfQuestions = gameController.getAmountOfQuestions();
    ui->amountOfQuestions->setText(amountOfQuestions);
    setLevelData(gameController.getLevel());
}

void GameWindow::setLevelData(int levelId) {
    QString startQuestion = gameController.getCurrentQuestion(levelId);
    QString firstAnswer = gameController.getCurrentAnswer(levelId, 0);
    QString secondAnswer = gameController.getCurrentAnswer(levelId, 1);
    QString thirdAnswer = gameController.getCurrentAnswer(levelId, 2);
    QString fourthAnswer = gameController.getCurrentAnswer(levelId, 3);
    QString currentQuestionNumber = QString::number(levelId + 1);
    QString points = QString::number(gameController.getPoints());

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
    changeCorrectAnswerColor(gameController.getCorrectAnswerId(gameController.getLevel()), true);
}
void GameWindow::on_checkAnswerButton_clicked()
{
    int btnId = getChosenId();
    int currentLevel = gameController.getLevel();
    bool isCorrect = gameController.isCorrectAnswer(currentLevel, btnId);
    if (isCorrect) {
        int curentPoints = gameController.getPoints();
        curentPoints++;
        gameController.setPoints(curentPoints);
    }
    changeCorrectAnswerColor(gameController.getCorrectAnswerId(currentLevel));
    ui->checkAnswerButton->hide();
    ui->nextQuestionButton->show();
}
void GameWindow::on_nextQuestionButton_clicked()
{
    resetRadioButtons();
    gameController.incLevel();
    int currentLevel = gameController.getLevel();
    int amountOfQuestions = gameController.getAmountOfQuestions().toInt();
    if (amountOfQuestions <= currentLevel) {
        QString points = QString::number(gameController.getPoints());
        ui->resultPointsValue->setText(points);
        ui->resultBox->show();
        ui->nextQuestionButton->hide();
        ui->currectQuestion->hide();
        ui->radioButtons->hide();
        if (_client) _client->setDataToServer(to_string(gameController.getPoints()));
        else gameController.setResult(to_string(gameController.getPoints()));
    } else {
        setLevelData(currentLevel);
        ui->checkAnswerButton->show();
        ui->nextQuestionButton->hide();
    }
}
