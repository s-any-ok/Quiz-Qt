#include "databaseconnection.h"

DatabaseConnection::DatabaseConnection()
{
    this->db = QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName("DRIVER={SQL Server};SERVER=DESKTOP-2AJ8NRV;DATABASE=HistoryQuiz;Trusted_Connection=yes;");
}

bool DatabaseConnection::Connect()
{
    if(this->db.open())
    {
        qDebug()<<"ERROR";
        return false;
    } else {
        qDebug()<<"Ok";
        return true;
    }

}

QSqlDatabase DatabaseConnection::getDB()
{
    return this->db;
}
