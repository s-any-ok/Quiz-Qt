#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QApplication>
#include <string>
#include "filemanager.h"

FileManager::FileManager(){
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}
 FileManager::~FileManager(){}

QJsonArray FileManager::getData(string fileName, string objName)
  {
    QString settings;
    QFile file;
    string folderPath = ":/resources/data/";
    string filePath = folderPath + fileName + ".json";
    QString fileNameUtf8 = QString::fromUtf8(filePath.c_str());
    file.setFileName(fileNameUtf8);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    settings = file.readAll();
    file.close();

    QJsonDocument json = QJsonDocument::fromJson(settings.toUtf8());
    if (json.isNull()) qWarning() << json.isNull();

    QJsonObject jsonObj = json.object();
    QString objNameUtf8 = QString::fromUtf8(objName.c_str());
    QJsonValue value = jsonObj.value(objNameUtf8);
    QJsonArray array = value.toArray();
    return array;
  }

void FileManager::setData(string fileName, string result)
  {
    string folderPath = "D:/Quiz/Quiz-Qt/data/";
    string filePath = folderPath + fileName + ".json";
    QString fileNameUtf8 = QString::fromUtf8(filePath.c_str());

    QFile file(fileNameUtf8);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonParseError JsonParseError;
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    file.close();
    QJsonObject RootObject = JsonDocument.object();
    QJsonArray ref = RootObject.find("results")->toArray();

    QString qresult = QString::fromStdString(result);
    auto data1 = QJsonObject(
    {
    qMakePair(QString("result"), QJsonValue(qresult)),
    qMakePair(QString("date"), QDateTime::currentDateTime().toString())
    });

    ref.push_back(QJsonValue(data1));
    RootObject.insert(QString("results"), QJsonValue(ref));
    JsonDocument.setObject(RootObject);

    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(JsonDocument.toJson());
    file.close();
  }
