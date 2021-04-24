#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <QJsonArray>
using namespace std;

class FileManager
{
public:
    FileManager();
    ~FileManager();
    QJsonArray getData(string fileName, string objName);
    void setData(string fileName, string result);
};

#endif // FILEMANAGER_H

