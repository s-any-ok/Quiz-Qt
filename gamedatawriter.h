#ifndef GAMEDATAWRITER_H
#define GAMEDATAWRITER_H
#include "datamanager.h"

class GameDataWriter
{
public:
    explicit GameDataWriter(DataManager);
    explicit GameDataWriter();
    void setDataManager(DataManager);
    ~GameDataWriter();
    void setResultToJson(string result);
private:
    DataManager datamanager;
    string resultsFileName = "results";
};

#endif // GAMEDATAWRITER_H
