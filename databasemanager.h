#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include "QtSql/QSqlDatabase"
#include "QDebug"
#include "QSqlQuery"
#include <string>
#include <QJsonArray>
using namespace std;

class DatabaseManager
{
private:
    QSqlDatabase db;
public:
    DatabaseManager();
    ~DatabaseManager();
    void setDB(QString databasePath, QString databaseName);
    void Connect();
    void Disconnect();

    QJsonArray getData(string fileName, string objName);
    void setData(string fileName, string result);
};

#endif // DATABASEMANAGER_H
