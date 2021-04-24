#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QApplication>
#include <QSqlError>
#include <string>
#include "databasemanager.h"


DatabaseManager::DatabaseManager()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

void DatabaseManager::setDB(QString databasePath, QString databaseName)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databasePath + databaseName);
}

DatabaseManager::~DatabaseManager(){}

void DatabaseManager::Connect()
{
    db.open();
}


void DatabaseManager::Disconnect()
{
    db.close();
}

QJsonArray DatabaseManager::getData(string fileName, string objName)
  {
    QJsonArray array;
    Connect();

    QSqlQuery query;
    QSqlQuery query2;
    query.exec("SELECT id, QuestionText FROM Question");

    auto question = QJsonObject();
    int i = 0;
    while (query.next())
    {
        auto answers = QJsonArray();
        QString id = query.value(0).toString();
        QString QuestionText = query.value(1).toString();
        QString IsCorrect;
        query2.exec("SELECT * FROM Answer where QuestionId = " + id);

        while (query2.next())
        {
            QString AnswerText = query2.value(1).toString();
            if (query2.value(2).toString() == "1") IsCorrect = query2.value(0).toString();

            answers.push_back(AnswerText);
        }

        question = QJsonObject(
        {
            qMakePair(QString("id"), id.toInt()),
            qMakePair(QString("question"), QuestionText),
            qMakePair(QString("correctAnswer"), IsCorrect.toInt() - i),
            qMakePair(QString("answers"), answers),
        });
        array.push_back(question);
        i += 4;
    }
    Disconnect();
    return array;
  }

void DatabaseManager::setData(string fileName, string result)
  {
//    string folderPath = "D:/Quiz/Quiz-Qt/data/";
//    string filePath = folderPath + fileName + ".json";
//    QString fileNameUtf8 = QString::fromUtf8(filePath.c_str());

//    QFile file(fileNameUtf8);
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    QJsonParseError JsonParseError;
//    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
//    file.close();
//    QJsonObject RootObject = JsonDocument.object();
//    QJsonArray ref = RootObject.find("results")->toArray();

//    QString qresult = QString::fromStdString(result);
//    auto data1 = QJsonObject(
//    {
//    qMakePair(QString("result"), QJsonValue(qresult)),
//    qMakePair(QString("date"), QDateTime::currentDateTime().toString())
//    });

//    ref.push_back(QJsonValue(data1));
//    RootObject.insert(QString("results"), QJsonValue(ref));
//    JsonDocument.setObject(RootObject);

//    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
//    file.write(JsonDocument.toJson());
//    file.close();

    Connect();
    QString qresult = QString::fromStdString(result);
//    QSqlQuery query(QString("INSERT INTO Results(id, date, result) VALUES(?, ?, ?)"));
//    query.bindValue(0, 0);
//    query.bindValue(1, qresult.toInt());
//    query.bindValue(2, QDateTime::currentDateTime().toString());
    QSqlQuery query;
        query.prepare("INSERT INTO Results(date, result) VALUES (:date, :result);");
        query.bindValue(":date", qresult.toInt());
        query.bindValue(":result", QDateTime::currentDateTime().toString());

        if(!query.exec()){
                qDebug() << "error insert into " << query.lastError();
            } else {
                qDebug() << "ok ";
            }
  }
