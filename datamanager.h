#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <string>
#include <QJsonArray>
#include "databasemanager.h"
using namespace std;

class DataManager
{
public:
    DataManager();
    ~DataManager();
    QJsonArray getData(string fileName, string objName);
    void setData(string fileName, string result);
private:
    DatabaseManager dbmanager;
};


#endif // DATAMANAGER_H
