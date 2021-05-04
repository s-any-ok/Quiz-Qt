#include "clientmanager.h"

ClientManager::ClientManager()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    socket = new QTcpSocket(this);
        connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
        connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));
}


ClientManager::~ClientManager()
{
}

QJsonArray ClientManager::getJsonData() {
    return dataJson;
}

void ClientManager::connectToHost()
{
    socket->connectToHost("127.0.0.1",5555);
}

void ClientManager::sockDisc()
{
    socket->deleteLater();
}

void ClientManager::sockReady()
{
    if (socket->waitForConnected(500))
    {
        socket->waitForReadyRead(500);
        Data = socket->readAll();
        std::string stdString(Data.constData(), Data.length());
        QString qstr = QString::fromStdString(stdString);
        DataStr = stdString;
        dataJson = getData("","");
    }
}

QJsonArray ClientManager::getData(string fileName, string objName)
  {
    string data = DataStr;
    int dataSize = DataStr.size();
    auto array = QJsonArray();
    auto question = QJsonObject();

    auto questions = new vector<string>;
    int sizeOfLasQuestion;

    for(int i = 0; i < 5; i++)
    {
        questions->push_back(data.substr(0, data.find("$$$")));
        sizeOfLasQuestion = data.substr(0, data.find("$$$")).size();
        dataSize -= sizeOfLasQuestion + 3;
        data = data.substr(sizeOfLasQuestion + 3, dataSize);
    }

    for(int i = 0; i < 5; i++)
    {
        string row = questions->at(i);
        int id = stoi(row.substr(row.find("--(id)--") + 8, row.find("--(correct answer)--") - row.find("--(id)--") - 8));
        int correctAnswer = stoi(row.substr(row.find("--(correct answer)--") + 20, row.find("--(question)--") - row.find("--(correct answer)--") - 20));
        string QuestionText = row.substr(row.find("--(question)--") + 14, row.find("--(answer 1)--") - row.find("--(question)--") - 14);
        auto answers = QJsonArray();
        string answer;
        for (int i = 1; i < 5; i++)
        {
            answer = row.substr(row.find("--(answer " + to_string(i) + ")--") + 14, row.find("--(answer " + to_string(i + 1) + ")--") - row.find("--(answer " + to_string(i) + ")--") - 14);
            answers.push_back(QString::fromStdString(answer));
        }

        question = QJsonObject(
        {
            qMakePair(QString("id"), QJsonValue(id)),
            qMakePair(QString("question"), QString::fromStdString(QuestionText)),
            qMakePair(QString("correctAnswer"), QJsonValue(correctAnswer)),
            qMakePair(QString("answers"), answers),
        });

        array.push_back(question);
    }

    return array;

  }

void ClientManager::getDataFromServer() {
    connectToHost();
    socket->write("get");
}

void ClientManager::setDataToServer(string data) {
    auto dataToSent = "r" + data;
    QByteArray byteArrayData(dataToSent.c_str(), dataToSent.length());
    socket->write(byteArrayData);
}

