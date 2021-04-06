#include "gamedatawriter.h"

GameDataWriter::GameDataWriter()
{
}

void GameDataWriter::setDataManager(DataManager dataManager)
{
    this->datamanager = dataManager;
}

GameDataWriter::GameDataWriter(DataManager dataManager)
{
    this->datamanager = dataManager;
}

GameDataWriter::~GameDataWriter()
{}

void GameDataWriter::setResultToJson(string result){
    this->datamanager.setDataToJson(this->resultsFileName, result);
}
