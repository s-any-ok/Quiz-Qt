#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "question.h"
#include <list>
#include <QtCore/QObject>
#include "gameinitializer.h"
using namespace std;

class GameController
{
public:
    explicit GameController(GameInitializer);
    ~GameController();
    void checkAnswer(int answerId);
    QString getCurrentQuestion(int num = 0);
    QString getCurrentAnswer(int num = 0, int answerId = 0);
    int getPoints();
    void setPoints(int points);
    int getLevel();
    void incLevel();
    QString getAmountOfQuestions();
    bool isCorrectAnswer(int level, int answerId);
    int getCorrectAnswerId(int level);

private:
    int points = 0;
    int currentLevel = 0;
    vector<Question> questions;

};

#endif // GAMECONTROLLER_H
