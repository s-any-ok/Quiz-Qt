#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QTextCodec>
#include <string>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include "databasemanager.h"
using namespace std;


class ClientManager : public QObject
{
    Q_OBJECT
public:
    ClientManager();
    ~ClientManager();

    QTcpSocket* socket;
    QByteArray Data;

public slots:
    void sockReady();
    void sockDisc();
    void connectToHost();
    void getDataFromServer();
    void setDataToServer(string data);

    QJsonArray getData(string fileName, string objName);
    QJsonArray getJsonData();

private:
    string DataStr;
    QJsonArray dataJson;
};

#endif // CLIENTMANAGER_H
