#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <string>
#include "datamanager.h"

DataManager::DataManager(){
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}
// DataManager::~DataManager(){}

QJsonArray DataManager::getDataFromJson(string fileName, string objName)
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

void DataManager::setDataToJson(string fileName, string result)
  {
    QFile file;
    string folderPath = ":/resources/data/";
    string filePath = folderPath + fileName + ".json";
    QString fileNameUtf8 = QString::fromUtf8(filePath.c_str());
    file.setFileName(fileNameUtf8);

    if(!file.open(QIODevice::ReadWrite)) {
        qDebug() << "File open error";
    } else {
        qDebug() <<"File open!";
    }
 // Insert a key-value pair using the QJsonObject object.
    QJsonObject jsonObject;
    QString qstr = QString::fromStdString(result);
    jsonObject.insert("result", qstr);
    jsonObject.insert("time", QDateTime::currentDateTime().toString());

 // Set the json object using QJsonDocument
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObject);

 // Write json to the file as text and close the file.
    file.write(jsonDoc.toJson());
    file.close();

    qDebug() << "Write to file";
  }
