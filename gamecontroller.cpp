#include "gamecontroller.h"
#include <QDebug>


GameController::GameController(GameInitializer gameInitializer)
{
    vector<Question> questions = gameInitializer.initQuestions();
    this->questions = questions;
}

GameController::~GameController(){}

QString GameController::getCurrentQuestion(int num)
{
    Question q = questions.at(num);
    QString qs = q.getQuestion().c_str();
    return qs;
}

QString GameController::getCurrentAnswer(int num, int answerId)
{
    Question question = questions.at(num);
    QString answer = question.getAnswerById(answerId).c_str();
    return answer;
}

QString GameController::getAmountOfQuestions()
{
    QString amount = QString::number(this->questions.size());
    return amount;
}

int GameController::getPoints()
{
    return this->points;
}

void GameController::setPoints(int points)
{
    this->points = points;
}

int GameController::getLevel()
{
    return this->currentLevel;
}

void GameController::incLevel()
{
    this->currentLevel++;
}

bool GameController::isCorrectAnswer(int level, int answerId)
{
    return getCorrectAnswerId(level) == answerId;
}

int GameController::getCorrectAnswerId(int level)
{
    Question question = questions.at(level);
    return question.getCorrectAnswerId();
}
