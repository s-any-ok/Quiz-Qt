#ifndef GAMEDATAWRITER_H
#define GAMEDATAWRITER_H
#include "datamanager.h"

class GameDataWriter
{
public:
    explicit GameDataWriter(DatabaseManager);
    explicit GameDataWriter();
    void setDataManager(DatabaseManager);
    ~GameDataWriter();
    void setResult(string result);
    void setResultToServer(string result);
private:
    DatabaseManager datamanager;
    string resultsFileName = "results";
};

#endif // GAMEDATAWRITER_H
