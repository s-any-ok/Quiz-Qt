#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include "QtSql/QSqlDatabase"
#include "QDebug"
#include "QSqlQuery"

class DatabaseConnection
{
private:
    QSqlDatabase db;
public:
    DatabaseConnection();
    bool Connect();
    void Disconnect();
    QSqlDatabase getDB();
};

#endif // DATABASECONNECTION_H
