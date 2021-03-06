#include "gameinitializer.h"
#include "datamanager.h"
#include "question.h"

#include <QJsonObject>
#include <QJsonArray>
#include <array>
#include <list>
#include <QString>
#include <iostream>

#include "clientmanager.h"

GameInitializer::GameInitializer(DatabaseManager dataManager)
{
    this->datamanager = dataManager;
}
GameInitializer::GameInitializer()
{
}

GameInitializer::~GameInitializer()
{

}

void GameInitializer::setDataManager(DatabaseManager dataManager)
{
    this->datamanager = dataManager;
}



vector<Question> GameInitializer::initQuestions()
{
    vector<Question> questions;
    QJsonArray data = this->datamanager.getData("questions", "questions");
    foreach (const QJsonValue & v, data) {
        int id = v.toObject().value("id").toInt();
        string question = v.toObject().value("question").toString().toLocal8Bit().constData();
        int correctAnswerId = v.toObject().value("correctAnswer").toInt();

        QJsonArray answers =  v.toObject().value("answers").toArray();
        vector<string> answersList;
        foreach (const QJsonValue & v, answers) {
            string answer = v.toString().toLocal8Bit().constData();
            answersList.push_back(answer);
        }
        Question q(id, correctAnswerId, question, answersList);
        questions.push_back(q);
    }
    return questions;
}

vector<Question> GameInitializer::initQuestionsFromServer(QJsonArray data)
{
    vector<Question> questions;

    foreach (const QJsonValue & v, data) {
        int id = v.toObject().value("id").toInt();
        string question = v.toObject().value("question").toString().toLocal8Bit().constData();
        int correctAnswerId = v.toObject().value("correctAnswer").toInt();

        QJsonArray answers =  v.toObject().value("answers").toArray();
        vector<string> answersList;
        foreach (const QJsonValue & v, answers) {
            string answer = v.toString().toLocal8Bit().constData();
            answersList.push_back(answer);
        }
        Question q(id, correctAnswerId, question, answersList);
        questions.push_back(q);
    }
    return questions;
}
