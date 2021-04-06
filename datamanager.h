#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <string>
#include <QJsonArray>
using namespace std;

class DataManager
{
public:
    DataManager();
    QJsonArray getDataFromJson(string fileName, string objName);
    void setDataToJson(string fileName, string result);
};

#endif // DATAMANAGER_H
